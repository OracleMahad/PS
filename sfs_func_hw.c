//
// Simple FIle System
// Student Name :
// Student Number :
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* optional */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
/***********/

#include "sfs_types.h"
#include "sfs_func.h"
#include "sfs_disk.h"
#include "sfs.h"

void dump_directory();

/* BIT operation Macros */
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

static struct sfs_super spb;	// superblock
static struct sfs_dir sd_cwd = { SFS_NOINO }; // current working directory

u_int32_t empty_block(){
	int i, j, k;
	int inode = 0;
	u_int8_t bitmap[512];
	u_int32_t  bitblock = SFS_BITBLOCKS(spb.sp_nblocks);
	for(i=0;i<bitblock;i++){
		disk_read( bitmap, SFS_MAP_LOCATION + i );
		for(j = 0; j < 512; j++){
			for(k = 0;k < 8;k++){
				if(!BIT_CHECK(bitmap[j],k)){
					BIT_SET(bitmap[j],k);
					disk_write( bitmap, SFS_MAP_LOCATION + i );
					return SFS_BLOCKSIZE * 8 * i +  j * 8 + k ;
				}
			}
		}
	}
	return -1; //full
}

void free_block(u_int32_t index){
	int i, j, k;
	u_int8_t bitmap[512];

	k = index % 8;
	j = (index/8) % SFS_BLOCKSIZE;
	i = (index/8) / SFS_BLOCKSIZE;

	disk_read( bitmap, SFS_MAP_LOCATION + i );
	BIT_CLEAR(bitmap[j],k);
	disk_write( bitmap, SFS_MAP_LOCATION + i );

}
	

void error_message(const char *message, const char *path, int error_code) {
	switch (error_code) {
	case -1:
		printf("%s: %s: No such file or directory\n",message, path); return;
	case -2:
		printf("%s: %s: Not a directory\n",message, path); return;
	case -3:
		printf("%s: %s: Directory full\n",message, path); return;
	case -4:
		printf("%s: %s: No block available\n",message, path); return;
	case -5:
		printf("%s: %s: Not a directory\n",message, path); return;
	case -6:
		printf("%s: %s: Already exists\n",message, path); return;
	case -7:
		printf("%s: %s: Directory not empty\n",message, path); return;
	case -8:
		printf("%s: %s: Invalid argument\n",message, path); return;
	case -9:
		printf("%s: %s: Is a directory\n",message, path); return;
	case -10:
		printf("%s: %s: Is not a file\n",message, path); return;
	default:
		printf("unknown error code\n");
		return;
	}
}

void sfs_mount(const char* path)
{
	if( sd_cwd.sfd_ino !=  SFS_NOINO )
	{
		//umount
		disk_close();
		printf("%s, unmounted\n", spb.sp_volname);
		bzero(&spb, sizeof(struct sfs_super));
		sd_cwd.sfd_ino = SFS_NOINO;
	}

	printf("Disk image: %s\n", path);

	disk_open(path);
	disk_read( &spb, SFS_SB_LOCATION );

	printf("Superblock magic: %x\n", spb.sp_magic);

	assert( spb.sp_magic == SFS_MAGIC );
	
	printf("Number of blocks: %d\n", spb.sp_nblocks);
	printf("Volume name: %s\n", spb.sp_volname);
	printf("%s, mounted\n", spb.sp_volname);
	
	sd_cwd.sfd_ino = 1;		//init at root
	sd_cwd.sfd_name[0] = '/';
	sd_cwd.sfd_name[1] = '\0';
}

void sfs_umount() {

	if( sd_cwd.sfd_ino !=  SFS_NOINO )
	{
		//umount
		disk_close();
		printf("%s, unmounted\n", spb.sp_volname);
		bzero(&spb, sizeof(struct sfs_super));
		sd_cwd.sfd_ino = SFS_NOINO;
	}
}

void sfs_touch(const char* path)
{
	int i, j;


	struct sfs_inode si;
	disk_read( &si, sd_cwd.sfd_ino );
	//for consistency
	assert( si.sfi_type == SFS_TYPE_DIR );

	//buffer for disk read
	struct sfs_dir sd[SFS_DENTRYPERBLOCK];
	//block access

	/********check exists********/
	if(path == NULL){
		return;
	} else {
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read( sd, si.sfi_direct[i] );

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(sd[j].sfd_ino==0) continue;
				if(!strcmp(sd[j].sfd_name, path)){//Already exists
					error_message("touch",path,-6);
					return;
				}
			}
		}
	}


	//allocate new block
	int newbie_ino = empty_block();
	if(newbie_ino==-1){
		error_message("touch",path,-4);//no block
		return;
	}


	/********allocate********/
	if(path == NULL){
		return;
	} else {
			if((si.sfi_size)/64 >= SFS_DENTRYPERBLOCK * SFS_NDIRECT){
			error_message("touch", path, -3);
			free_block(newbie_ino);
			return;
		}
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) {// dir allocate
				int newdir_ino = empty_block();
				if(newdir_ino==-1){
					error_message("touch",path,-4);//no block
					free_block(newbie_ino);
					return;
				}
				si.sfi_direct[i] = newdir_ino;
				struct sfs_dir newdir[SFS_DENTRYPERBLOCK];
				bzero(&newdir,SFS_BLOCKSIZE);
				disk_write( &newdir, si.sfi_direct[i] );
			}
			disk_read( sd, si.sfi_direct[i] );

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(sd[j].sfd_ino==0){
					sd[j].sfd_ino = newbie_ino;
					strncpy( sd[j].sfd_name, path, SFS_NAMELEN );
					disk_write( sd, si.sfi_direct[i] );
					goto end_alc;
				}
			}
		}
		// error_message("touch", path, -3);
	}
	end_alc:
	si.sfi_size += sizeof(struct sfs_dir);
	disk_write( &si, sd_cwd.sfd_ino );

	struct sfs_inode newbie;

	bzero(&newbie,SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
	newbie.sfi_size = 0;
	newbie.sfi_type = SFS_TYPE_FILE;

	disk_write( &newbie, newbie_ino );

}



void sfs_cd(const char* path)
{
	int i, j, count;
	u_int32_t answer = 1;
	char sfd_name_goal[SFS_NAMELEN];
	struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
	struct sfs_inode inode;
	disk_read(&inode, sd_cwd.sfd_ino);

	if(path == NULL){
		return;
	} else {
		count = 0;
		for(i=0; i < SFS_NDIRECT; i++) {
			if (inode.sfi_direct[i] == 0) break;
			disk_read(dir_entry, inode.sfi_direct[i]);

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(!strcmp(dir_entry[j].sfd_name, path)){
					answer = dir_entry[j].sfd_ino;
					strcpy(sfd_name_goal, dir_entry[j].sfd_name);
					count++;
				}
			}
		}
		if(count == 0) {
			error_message("cd",path, -1);
			return;
		}
	}
	struct sfs_inode inode_goal;
	disk_read(&inode_goal, answer);
	if(inode_goal.sfi_type == SFS_TYPE_FILE) {
		error_message("cd",path, -5);
		return;
	}
	sd_cwd.sfd_ino = answer;		
	strcpy(sd_cwd.sfd_name, sfd_name_goal);
	// printf("Not Implemented\n");
}

void sfs_ls(const char* path)
{
	int i, j, count;
	u_int32_t answer = 1;
	struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];
	struct sfs_inode inode;
	disk_read(&inode, sd_cwd.sfd_ino);

	if(path == NULL){
		answer = sd_cwd.sfd_ino;
	} else {
		count = 0;
		for(i=0; i < SFS_NDIRECT; i++) {
			if (inode.sfi_direct[i] == 0) break;
			disk_read(dir_entry, inode.sfi_direct[i]);

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(!strcmp(dir_entry[j].sfd_name, path)){
					answer = dir_entry[j].sfd_ino;
					count++;
				}
			}
		}
		if(count == 0) {
			error_message("ls",path, -1);
			return;
		}
	}

	struct sfs_inode inode_goal;
	struct sfs_dir dir_entry_goal[SFS_DENTRYPERBLOCK];
	disk_read(&inode_goal, answer);


	if (inode_goal.sfi_type == SFS_TYPE_DIR) {
		for(i=0; i < SFS_NDIRECT; i++) {
			if (inode_goal.sfi_direct[i] == 0) break;
			disk_read(dir_entry_goal, inode_goal.sfi_direct[i]);

			struct sfs_inode inode2;
			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(dir_entry_goal[j].sfd_ino==0) continue;
				printf("%s", dir_entry_goal[j].sfd_name);
				disk_read(&inode2,dir_entry_goal[j].sfd_ino);
				if (inode2.sfi_type == SFS_TYPE_DIR) {
					printf("/\t");
				} else {
					printf("\t");
				}
				
			}
			printf("\n");
		}
	} else {
		printf("%s\n", path);
	}
	// printf("Not Implemented\n");
}

void sfs_mkdir(const char* org_path) 
{
	int i, j;

	struct sfs_inode si;
	disk_read( &si, sd_cwd.sfd_ino );
	//for consistency
	assert( si.sfi_type == SFS_TYPE_DIR );

	//buffer for disk read
	struct sfs_dir sd[SFS_DENTRYPERBLOCK];
	//block access

	/********check exists********/
	if(org_path == NULL){
		return;
	} else {
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read( sd, si.sfi_direct[i] );

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(sd[j].sfd_ino==0) continue;
				if(!strcmp(sd[j].sfd_name, org_path)){//Already exists
					error_message("mkdir",org_path,-6);
					return;
				}
			}
		}
	}


	//allocate new block
	int newbie_ino = empty_block();
	if(newbie_ino==-1){
		error_message("mkdir",org_path,-4);//no block
		return;
	}

	int newdir_ino;
	int alcdir_blk;

	/********allocate********/
	if(org_path == NULL){
		return;
	} else {
		if((si.sfi_size)/64 >= SFS_DENTRYPERBLOCK * SFS_NDIRECT){// check dir full
			error_message("mkdir", org_path, -3);
			free_block(newbie_ino);
			return;
		}

		alcdir_blk = empty_block();
		if(alcdir_blk==-1){
			error_message("mkdir",org_path,-4);//no block
			free_block(newbie_ino);
			return;
		}

		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) {// dir allocate
				newdir_ino = empty_block();
				if(newdir_ino==-1){
					error_message("mkdir",org_path,-4);//no block
					free_block(newbie_ino);
					free_block(alcdir_blk);
					return;
				}
				si.sfi_direct[i] = newdir_ino;
				struct sfs_dir newdir[SFS_DENTRYPERBLOCK];
				bzero(&newdir,SFS_BLOCKSIZE);
				disk_write( &newdir, si.sfi_direct[i] );
			}
			disk_read( sd, si.sfi_direct[i] );

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(sd[j].sfd_ino==0){
					sd[j].sfd_ino = newbie_ino;
					strncpy( sd[j].sfd_name, org_path, SFS_NAMELEN );
					disk_write( sd, si.sfi_direct[i] );
					goto end_alc;
				}
			}
		}
		// error_message("mkdir", org_path, -3);
	}
	end_alc:
	si.sfi_size += sizeof(struct sfs_dir);
	disk_write( &si, sd_cwd.sfd_ino );

	struct sfs_inode newbie;

	bzero(&newbie,SFS_BLOCKSIZE); // initalize sfi_direct[] and sfi_indirect
	newbie.sfi_size = 128;
	newbie.sfi_type = SFS_TYPE_DIR;
	newbie.sfi_direct[0] = alcdir_blk;

	struct sfs_dir alcdir[SFS_DENTRYPERBLOCK];
	bzero(&alcdir,SFS_BLOCKSIZE);
	alcdir[0].sfd_ino = newbie_ino;
	strncpy( alcdir[0].sfd_name, ".", SFS_NAMELEN );
	alcdir[1].sfd_ino = sd_cwd.sfd_ino;
	strncpy( alcdir[1].sfd_name, "..", SFS_NAMELEN );
	
	disk_write( &alcdir, alcdir_blk);

	disk_write( &newbie, newbie_ino );
	
	// printf("Not Implemented\n");
}

void sfs_rmdir(const char* org_path) 
{	
	if(!strcmp(".", org_path)){
		error_message("rmdir",org_path, -8);//Invalid argument
		return;
	}
	
	int i, j, k;
	struct sfs_inode si;
	disk_read( &si, sd_cwd.sfd_ino );
	//for consistency
	assert( si.sfi_type == SFS_TYPE_DIR );

	//buffer for disk read
	struct sfs_dir sd[SFS_DENTRYPERBLOCK];

	if(org_path == NULL){
		return;
	} else {
		int count = 0;
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read(sd, si.sfi_direct[i]);

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(!strcmp(sd[j].sfd_name, org_path)){
					struct sfs_inode rminode;

					disk_read(&rminode, sd[j].sfd_ino);
					if(rminode.sfi_type == SFS_TYPE_FILE){
						error_message("rmdir", org_path, -5);//Not a directory
						return;
					}
					if(rminode.sfi_size>128){
						error_message("rmdir", org_path, -7);//Directory not empty
						return;
					}


					for(k=0; k < SFS_NDIRECT; k++) {
						if (rminode.sfi_direct[k] == 0) break;
						free_block(rminode.sfi_direct[k]);
					}
					free_block(sd[j].sfd_ino);
					sd[j].sfd_ino = 0;
					si.sfi_size -= sizeof(struct sfs_dir);
					
					disk_write(sd, si.sfi_direct[i]);
							
					count++;
				}
			}
		}
		if(count == 0) {
			error_message("rmdir",org_path, -1);//No such file or directory
			return;
		}
		disk_write( &si, sd_cwd.sfd_ino );
	}
	// printf("Not Implemented\n");
}

void sfs_mv(const char* src_name, const char* dst_name) 
{
	int i, j;


	struct sfs_inode si;
	disk_read( &si, sd_cwd.sfd_ino );
	//for consistency
	assert( si.sfi_type == SFS_TYPE_DIR );

	//buffer for disk read
	struct sfs_dir sd[SFS_DENTRYPERBLOCK];
	//block access

	/********check exists dst********/
	if(dst_name == NULL){
		return;
	} else {
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read( sd, si.sfi_direct[i] );

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(sd[j].sfd_ino==0) continue;
				if(!strcmp(sd[j].sfd_name, dst_name)){//Already exists
					error_message("mv",dst_name,-6);
					return;
				}
			}
		}
	}

	if(src_name == NULL){//rename
		return;
	} else {
		int count = 0;
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read(sd, si.sfi_direct[i]);

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(!strcmp(sd[j].sfd_name, src_name)){
					strcpy(sd[j].sfd_name, dst_name);
					disk_write(sd, si.sfi_direct[i]);
					count++;
				}
			}
		}
		if(count == 0) {
			error_message("mv",src_name, -1);
			return;
		}
	}


}

void sfs_rm(const char* path) 
{	
	int i, j, k;
	struct sfs_inode si;
	disk_read( &si, sd_cwd.sfd_ino );
	//for consistency
	assert( si.sfi_type == SFS_TYPE_DIR );

	//buffer for disk read
	struct sfs_dir sd[SFS_DENTRYPERBLOCK];

	if(path == NULL){
		return;
	} else {
		int count = 0;
		for(i=0; i < SFS_NDIRECT; i++) {
			if (si.sfi_direct[i] == 0) break;
			disk_read(sd, si.sfi_direct[i]);

			for(j=0; j < SFS_DENTRYPERBLOCK;j++) {
				if(!strcmp(sd[j].sfd_name, path)){
					struct sfs_inode rminode;

					disk_read(&rminode, sd[j].sfd_ino);
					if(rminode.sfi_type == SFS_TYPE_DIR){
						error_message("rm", path, -9);//Is a directory
						return;
					}

					for(k=0; k < SFS_NDIRECT; k++) {
						if (rminode.sfi_direct[k] == 0) break;
						free_block(rminode.sfi_direct[k]);
					}
					//del indirect
					free_block(sd[j].sfd_ino);
					sd[j].sfd_ino = 0;
					si.sfi_size -= sizeof(struct sfs_dir);////indirect랑 사이즈 고려해야함
					
					disk_write(sd, si.sfi_direct[i]);
					
							
					count++;
				}
			}
		}
		if(count == 0) {
			error_message("rm",path, -1);//No such file or directory
			return;
		}
		disk_write( &si, sd_cwd.sfd_ino );
	}
	// printf("Not Implemented\n");
}

void sfs_cpin(const char* local_path, const char* path) 
{
	// printf("Not Implemented\n");
}

void sfs_cpout(const char* local_path, const char* path) 
{
	// printf("Not Implemented\n");
}

void dump_inode(struct sfs_inode inode) {
	int i;
	struct sfs_dir dir_entry[SFS_DENTRYPERBLOCK];

	printf("size %d type %d direct ", inode.sfi_size, inode.sfi_type);
	for(i=0; i < SFS_NDIRECT; i++) {
		printf(" %d ", inode.sfi_direct[i]);
	}
	printf(" indirect %d",inode.sfi_indirect);
	printf("\n");

	if (inode.sfi_type == SFS_TYPE_DIR) {
		for(i=0; i < SFS_NDIRECT; i++) {
			if (inode.sfi_direct[i] == 0) break;
			disk_read(dir_entry, inode.sfi_direct[i]);
			dump_directory(dir_entry);
		}
	}

}

void dump_directory(struct sfs_dir dir_entry[]) {
	int i;
	struct sfs_inode inode;
	for(i=0; i < SFS_DENTRYPERBLOCK;i++) {
		printf("%d %s\n",dir_entry[i].sfd_ino, dir_entry[i].sfd_name);
		disk_read(&inode,dir_entry[i].sfd_ino);
		if (inode.sfi_type == SFS_TYPE_FILE) {
			printf("\t");
			dump_inode(inode);
		}
	}
}

void sfs_dump() {
	// dump the current directory structure
	struct sfs_inode c_inode;

	disk_read(&c_inode, sd_cwd.sfd_ino);
	printf("cwd inode %d name %s\n",sd_cwd.sfd_ino,sd_cwd.sfd_name);
	dump_inode(c_inode);
	printf("\n");

}
