/*
 *  Copyright (C) 2023 CS416 Rutgers CS
 *	Tiny File System
 *	File:	rufs.c
 *
 */

#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <libgen.h>
#include <limits.h>

#include "block.h"
#include "rufs.h"

char diskfile_path[PATH_MAX];

// Declare your in-memory data structures here

/* 
 * Get available inode number from bitmap
 */
int get_avail_ino() {

	// Step 1: Read inode bitmap from disk
	
	// Step 2: Traverse inode bitmap to find an available slot

	// Step 3: Update inode bitmap and write to disk 

	return 0;
}

/* 
 * Get available data block number from bitmap
 */
int get_avail_blkno() {

	// Step 1: Read data block bitmap from disk
	
	// Step 2: Traverse data block bitmap to find an available slot

	// Step 3: Update data block bitmap and write to disk 

	return 0;
}

/* 
 * inode operations
 */
int readi(uint16_t ino, struct inode *inode) {

  // Step 1: Get the inode's on-disk block number

  // Step 2: Get offset of the inode in the inode on-disk block

  // Step 3: Read the block from disk and then copy into inode structure

	return 0;
}

int writei(uint16_t ino, struct inode *inode) {

	// Step 1: Get the block number where this inode resides on disk
	
	// Step 2: Get the offset in the block where this inode resides on disk

	// Step 3: Write inode to disk 

	return 0;
}


/* 
 * directory operations
 */
int dir_find(uint16_t ino, const char *fname, size_t name_len, struct dirent *dirent) {

  // Step 1: Call readi() to get the inode using ino (inode number of current directory)

  // Step 2: Get data block of current directory from inode

  // Step 3: Read directory's data block and check each directory entry.
  //If the name matches, then copy directory entry to dirent structure

	return 0;
}

int dir_add(struct inode dir_inode, uint16_t f_ino, const char *fname, size_t name_len) {

	// Step 1: Read dir_inode's data block and check each directory entry of dir_inode
	
	// Step 2: Check if fname (directory name) is already used in other entries

	// Step 3: Add directory entry in dir_inode's data block and write to disk

	// Allocate a new data block for this directory if it does not exist

	// Update directory inode

	// Write directory entry

	return 0;
}

int dir_remove(struct inode dir_inode, const char *fname, size_t name_len) {

	// Step 1: Read dir_inode's data block and checks each directory entry of dir_inode
	
	// Step 2: Check if fname exist

	// Step 3: If exist, then remove it from dir_inode's data block and write to disk

	return 0;
}

/* 
 * namei operation
 */
int get_node_by_path(const char *path, uint16_t ino, struct inode *inode) {
	
	// Step 1: Resolve the path name, walk through path, and finally, find its inode.
	// Note: You could either implement it in a iterative way or recursive way

	return 0;
}

/* 
 * Make file system
 */
int rufs_mkfs() {

	// Call dev_init() to initialize (Create) Diskfile

	// write superblock information

	// initialize inode bitmap

	// initialize data block bitmap

	// update bitmap information for root directory

	// update inode for root directory

	return 0;
}


/* 
 * FUSE file operations
 */
static void *rufs_init(struct fuse_conn_info *conn) {

	// Step 1a: If disk file is not found, call mkfs

  // Step 1b: If disk file is found, just initialize in-memory data structures
  // and read superblock from disk

	return NULL;
}

static void rufs_destroy(void *userdata) {

	// Step 1: De-allocate in-memory data structures

	// Step 2: Close diskfile

}

static int rufs_getattr(const char *path, struct stat *stbuf) {

	// Step 1: call get_node_by_path() to get inode from path

	// Step 2: fill attribute of file into stbuf from inode

		stbuf->st_mode   = S_IFDIR | 0755;
		stbuf->st_nlink  = 2;
		time(&stbuf->st_mtime);

	return 0;
}

static int rufs_opendir(const char *path, struct fuse_file_info *fi) {

	// Step 1: Call get_node_by_path() to get inode from path

	// Step 2: If not find, return -1

    return 0;
}

static int rufs_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {

	// Step 1: Call get_node_by_path() to get inode from path

	// Step 2: Read directory entries from its data blocks, and copy them to filler

	return 0;
}


static int rufs_mkdir(const char *path, mode_t mode) {

	// Step 1: separate parent directory path and target directory name

	// Step 2: Call get_node_by_path() to get inode of parent directory

	// Step 3: Call get_avail_ino() to get an available inode number

	// Step 4: Call dir_add() to add directory entry of target directory to parent directory

	// Step 5: Update inode for target directory

	// Step 6: Call writei() to write inode to disk
	

	return 0;
}

static int rufs_rmdir(const char *path) {

	// Step 1: Use dirname() and basename() to separate parent directory path and target directory name

	// Step 2: Call get_node_by_path() to get inode of target directory

	// Step 3: Clear data block bitmap of target directory

	// Step 4: Clear inode bitmap and its data block

	// Step 5: Call get_node_by_path() to get inode of parent directory

	// Step 6: Call dir_remove() to remove directory entry of target directory in its parent directory

	return 0;
}

static int rufs_releasedir(const char *path, struct fuse_file_info *fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_create(const char *path, mode_t mode, struct fuse_file_info *fi) {

	// Step 1: Use dirname() and basename() to separate parent directory path and target file name

	// Step 2: Call get_node_by_path() to get inode of parent directory

	// Step 3: Call get_avail_ino() to get an available inode number

	// Step 4: Call dir_add() to add directory entry of target file to parent directory

	// Step 5: Update inode for target file

	// Step 6: Call writei() to write inode to disk

	return 0;
}

static int rufs_open(const char *path, struct fuse_file_info *fi) {

	// Step 1: Call get_node_by_path() to get inode from path

	// Step 2: If not find, return -1

	return 0;
}

static int rufs_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi) {

	// Step 1: You could call get_node_by_path() to get inode from path

	// Step 2: Based on size and offset, read its data blocks from disk

	// Step 3: copy the correct amount of data from offset to buffer

	// Note: this function should return the amount of bytes you copied to buffer
	return 0;
}

static int rufs_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi) {
	// Step 1: You could call get_node_by_path() to get inode from path

	// Step 2: Based on size and offset, read its data blocks from disk

	// Step 3: Write the correct amount of data from offset to disk

	// Step 4: Update the inode info and write it to disk

	// Note: this function should return the amount of bytes you write to disk
	return size;
}

static int rufs_unlink(const char *path) {

	// Step 1: Use dirname() and basename() to separate parent directory path and target file name

	// Step 2: Call get_node_by_path() to get inode of target file

	// Step 3: Clear data block bitmap of target file

	// Step 4: Clear inode bitmap and its data block

	// Step 5: Call get_node_by_path() to get inode of parent directory

	// Step 6: Call dir_remove() to remove directory entry of target file in its parent directory

	return 0;
}

static int rufs_truncate(const char *path, off_t size) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_release(const char *path, struct fuse_file_info *fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
	return 0;
}

static int rufs_flush(const char * path, struct fuse_file_info * fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_utimens(const char *path, const struct timespec tv[2]) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}


static struct fuse_operations rufs_ope = {
	.init		= rufs_init,
	.destroy	= rufs_destroy,

	.getattr	= rufs_getattr,
	.readdir	= rufs_readdir,
	.opendir	= rufs_opendir,
	.releasedir	= rufs_releasedir,
	.mkdir		= rufs_mkdir,
	.rmdir		= rufs_rmdir,

	.create		= rufs_create,
	.open		= rufs_open,
	.read 		= rufs_read,
	.write		= rufs_write,
	.unlink		= rufs_unlink,

	.truncate   = rufs_truncate,
	.flush      = rufs_flush,
	.utimens    = rufs_utimens,
	.release	= rufs_release
};


int main(int argc, char *argv[]) {
	int fuse_stat;

	getcwd(diskfile_path, PATH_MAX);
	strcat(diskfile_path, "/DISKFILE");

	fuse_stat = fuse_main(argc, argv, &rufs_ope, NULL);

	return fuse_stat;
}



/*
 *  Copyright (C) 2023 CS416 Rutgers CS
 *	Tiny File System
 *	File:	rufs.c
 *
 */

#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <libgen.h>
#include <limits.h>

#include "block.h"
#include "rufs.h"
#define INODE_BITMAP_BLKNO 1
#define DB_BITMAP_BLKNO 2
#define INODE_BLOCK_START 3
#define DATA_BLOCK_START 67


char diskfile_path[PATH_MAX]; // From what I read it seems PATH_MAX comes from limits.h

// Declare your in-memory data structures here
typedef unsigned char* bitmap_buffer[BLOCK_SIZE];


static struct superblock super_block; 	/* The in-memory superblock (initialized in rufs_init) */
unsigned char* super_block_buffer[BLOCK_SIZE];
bitmap_buffer inode_bitmap_buffer[BLOCK_SIZE];
bitmap_buffer db_bitmap_buffer[BLOCK_SIZE];


// Other utility variables and data structures

uint16_t i_pblk = BLOCK_SIZE / sizeof(struct inode);		/* Number of inodes allowed per disk block */
uint16_t dirent_pblk = BLOCK_SIZE / sizeof(struct inode);	/* Number of dirents allowed per disk block */

#define TYPE_FILE 0		/* Indicates inode type for files */
#define TYPE_DIR 1		/* Indicates inode type for directories */

#define TESTDIR "/"

/* 
 * Get available inode number from bitmap
 */
int get_avail_ino() {
    // Step 1: Read inode bitmap from disk
    int retstat = bio_read(INODE_BITMAP_BLKNO, inode_bitmap_buffer);
    if (retstat < 0) {
     	perror("inode bitmap block NOT read from disk in {get_avail_ino}");
        return retstat;
    }
    // Step 2: Traverse inode bitmap to find an available slot
    int i;
    for (i = 0; i < MAX_INUM; i++) {
        if (get_bitmap(inode_bitmap_buffer, i) == 0) break;
    }

    if (i == MAX_INUM) // No inodes available
        return -ENOSPC;

    // Step 3: Update inode bitmap and write to disk
    set_bitmap(inode_bitmap_buffer, i);
    retstat = bio_write(super_block.i_bitmap_blk, inode_bitmap_buffer);
    if (retstat < 0) {
        perror("inode bitmap block FAILED to write to disk in {get_avail_ino}");
        return retstat;
    }

	// instead of zero return the inode number
    return i;
}


/* 
 * Get available data block number from bitmap
 */
int get_avail_blkno() {
    // Step 1: Read data block bitmap from disk
    int retstat = bio_read(super_block.d_bitmap_blk, db_bitmap_buffer);
    if (retstat < 0) {
        perror("db_bitmap_block NOT read from disk in {get_avail_blkno}");
        return retstat;
    }
    // Step 2: Traverse data block bitmap to find an available slot
    int i;
    for (i = 0; i < MAX_DNUM; i++) {
        if (get_bitmap(db_bitmap_buffer, i) == 0) break;
    }

    if (i == MAX_DNUM) // No data blocks available
        return -ENOSPC;

    // Step 3: Update data block bitmap and write to disk 
    set_bitmap(db_bitmap_buffer, i);
    retstat = bio_write(super_block.d_bitmap_blk, db_bitmap_buffer); // Write the entire block

    if (retstat < 0) {
        perror("db_bitmap_block NOT updated in disk in {get_avail_blkno}");
        return retstat;
    }

    return i;
}

/* 
 * inode operations
 */
int readi(uint16_t ino, struct inode *inode) {
	// printf("In readi \n");

    // Step 1: Get the inode's on-disk block number
    uint16_t inode_total_size = ino * sizeof(struct inode);
    uint16_t blk_num = super_block.i_start_blk + (inode_total_size / BLOCK_SIZE);

	// Step 2: Get offset of the inode in the inode on-disk block
    uint16_t offset = inode_total_size % BLOCK_SIZE;

    // Step 3: Read the block from disk and then copy into inode structure
    static char db_buffer[BLOCK_SIZE]; // Use static allocation
	for (int i = 0; i < BLOCK_SIZE; i++) {
        db_buffer[i] = 0;
    }
    int retstat = bio_read(blk_num, db_buffer);
    if (retstat < 0) {
        perror("inode_number NOT read from disk (writei) \n");
        return retstat;
    }

    // Copy only the inode data from the read buffer
    memcpy(inode, db_buffer + offset, sizeof(struct inode));
	
    return 0;
}


int writei(uint16_t ino, struct inode *inode) {
    // Step 1: Get the block number where this inode resides on disk
    uint16_t inode_total_size = ino * sizeof(struct inode);
    uint16_t blk_num = super_block.i_start_blk + (inode_total_size / BLOCK_SIZE);

	// Step 2: Get offset of the inode in the inode on-disk block
    uint16_t offset = inode_total_size % BLOCK_SIZE;

    // Step 2: Read the block from disk where the inode is located
    static char db_buffer[BLOCK_SIZE]; // Use static allocation
    for (int i = 0; i < BLOCK_SIZE; i++) {
        db_buffer[i] = 0;
    }

	//Create an in-memory copy (i.e data_block_buffer) of the data block that has the inode
    int retstat = bio_read(blk_num, db_buffer);
    if (retstat < 0) {
        perror("inode_number NOT updated on disk(writei) \n");
        return retstat;
    }

    //Update the in-memory copy (i.e data_block_buffer)=> update the particular inode stored in this data block
	memcpy(db_buffer + offset, inode, sizeof(struct inode));

	// Step 3: Write inode to disk 
	// basically write the updated in-memory copy of the data block to disk
    retstat = bio_write(blk_num, db_buffer);
    if (retstat < 0) {
        return retstat;
    }

    return 0;
}



/* 
 * directory operations
 */
int dir_find(uint16_t ino, const char *fname, size_t name_len, struct dirent *dirent) {
    // Step 1: Call readi() to get the inode using ino
    static struct inode cur_inode; // Using static allocation

    int retstat = readi(ino, &cur_inode);
    if (retstat < 0) {
        return retstat;
    }

    // Step 2: Get ALL the data blocks of current directory from inode
    static char curr_dir_block[BLOCK_SIZE]; // Using static allocation

    for (int block = 0; block < 16; block++) { 
		// Using direct pointers
        if (cur_inode.direct_ptr[block] == 0) {
            break; // Exit loop if direct pointer is empty
        }

        // Read directory's data block
        retstat = bio_read(cur_inode.direct_ptr[block], curr_dir_block);
        if (retstat < 0) {
            return retstat;
        }

        // Check each directory entry within the block
        for (int i = 0; i < dirent_pblk; i++) {
            struct dirent *cur_dirent = (struct dirent *)(curr_dir_block + (i * sizeof(struct dirent)));

            if ((cur_dirent->valid == 1) && (strncmp(cur_dirent->name, fname, name_len) == 0)) {
                memcpy(dirent, cur_dirent, sizeof(struct dirent));
                return 0; // Entry found
            }
        }
    }

    return -ENOENT; // Entry not found
}

int dir_add(struct inode dir_inode, uint16_t f_ino, const char *fname, size_t name_len) {
    static char rd_buf[BLOCK_SIZE];
    static struct dirent new_dirent;

    // Initialize new dirent
    new_dirent.ino = f_ino;
    new_dirent.valid = 1;
    strncpy(new_dirent.name, fname, name_len);
    new_dirent.len = name_len;

    // Check if directory name already exists
    int retstat = dir_find(dir_inode.ino, fname, name_len, &new_dirent);
    if (retstat == 0) {
        return -EEXIST;
    } else if (retstat != -ENOENT) {
        return retstat;
    }

    int found = 0;
    for (int b = 0; b < 16; b++) {
        if (dir_inode.direct_ptr[b] == 0) {
            int new_blk = get_avail_blkno();
            if (new_blk < 0) return new_blk;

            dir_inode.direct_ptr[b] = new_blk;
            memset(rd_buf, 0, BLOCK_SIZE);
            memcpy(rd_buf, &new_dirent, sizeof(struct dirent));

            // Initialize remaining slots as empty
            struct dirent *cur_dirent;
            for (int d = 1; d < dirent_pblk; d++) {
                cur_dirent = (struct dirent *)(rd_buf + (d * sizeof(struct dirent)));
                cur_dirent->valid = 0;
            }

            retstat = bio_write(new_blk, rd_buf);
            if (retstat < 0) return retstat;

            found = 1;
            break;
        } else {
            retstat = bio_read(dir_inode.direct_ptr[b], rd_buf);
            if (retstat < 0) return retstat;

            for (int i = 0; i < dirent_pblk; i++) {
                struct dirent *cur_dirent = (struct dirent *)(rd_buf + (i * sizeof(struct dirent)));
                if (cur_dirent->valid == 0) {
                    memcpy(cur_dirent, &new_dirent, sizeof(struct dirent));
                    retstat = bio_write(dir_inode.direct_ptr[b], rd_buf);
                    if (retstat < 0) return retstat;
                    found = 1;
                    break;
                }
            }

            if (found) break;
        }
    }

    if (!found) return -ENOSPC;

    // Write updated dir_inode back to disk
    retstat = writei(dir_inode.ino, &dir_inode);
    if (retstat < 0) return retstat;

    return 0;
}


int dir_remove(struct inode dir_inode, const char *fname, size_t name_len) {

	// Step 1: Read dir_inode's data block and checks each directory entry of dir_inode
	
	// Step 2: Check if fname exist

	// Step 3: If exist, then remove it from dir_inode's data block and write to disk

	return 0;
}

/* 
 * namei operation
 */
int get_node_by_path(const char *path, uint16_t ino, struct inode *inode) {
	// printf("In get_node_by_path Path: %s\n", path);

    char temp_path[PATH_MAX]; // Static allocation for path
    strncpy(temp_path, path, PATH_MAX - 1);
    temp_path[PATH_MAX - 1] = '\0'; // Ensure null termination
	// printf("temp_path: %s \n", temp_path);


    char *token;
    const char delim[2] = "/";
    int retstat = 0;

    // Base cases: Empty path or root directory
    if (strlen(temp_path) == 0 || strcmp(temp_path, "/") == 0) {
		// printf("Empty Path \n");=> ino of the root of the path is the is the final ino
        retstat = readi(ino, inode);
        if (retstat < 0) {
            return retstat;
        }
        return retstat;
    }

    // Iterative approach
    token = strtok(temp_path, delim);

    while (token != NULL) {
		// printf("Token: %s \n", temp_path);

        struct dirent matched_dirent;
        retstat = dir_find(ino, token, strlen(token), &matched_dirent);

        if (retstat == -ENOENT) {
            // printf("NO such named dirent in the given ino of root_dir in get_node_by_path \n");
            return -ENOENT;
        } else if (retstat < 0) {
            return retstat;
        }

        ino = matched_dirent.ino; // Update the inode number for the next iteration
        token = strtok(NULL, delim);
		// Ex. /foo/break => ino = 0 token = foo => matched_dirent
    }

    // Final readi call for the last token
    retstat = readi(ino, inode);
    if (retstat < 0) {
        return retstat;
    }

    return 0;
}

void init_superblock() {
    super_block.magic_num = MAGIC_NUM;
    super_block.max_inum = MAX_INUM;
    super_block.max_dnum = MAX_DNUM;
    super_block.i_bitmap_blk = INODE_BITMAP_BLKNO;
    super_block.d_bitmap_blk = DB_BITMAP_BLKNO;
    super_block.i_start_blk = INODE_BLOCK_START;
    super_block.d_start_blk = DATA_BLOCK_START;
}

/* 
 * Make file system
 */
int rufs_mkfs() {

	// Call dev_init() to initialize (Create) Diskfile

	dev_init(diskfile_path);

	// write superblock information

	// initialising => update the in-memory copy of super block
	init_superblock();

	// write the in-memory copy to disk 
	// Since the all operations on disk should be of BLOCK_SIZE and our in-memory copy of superblock is not that big we copy them in a buffer of size BLOCK_SIZE and then write to the disk and the desired block num location
    memset(super_block_buffer, 0, BLOCK_SIZE);
    memcpy(super_block_buffer, &super_block, sizeof(super_block));

	// write the super_block_buffer to disk at data block num 0
	if (bio_write(0, super_block_buffer) < 0) {
		perror("super_block_buffer NOT able to write to disk during initialisation(rufs_mkfs)");
		exit(EXIT_FAILURE);
	}

	// initialize inode bitmap

	// we know the total bits to be assigned => convert it to bytes and set all bytes to 0 initially 
	memset(inode_bitmap_buffer,0, BLOCK_SIZE);

	// update bitmap information for root directory

	// Now as we know the first node should be the root node => set the bit corresponding to the first inode and write the in-memory copy to disk 
	set_bitmap(inode_bitmap_buffer, 0);

	// Writing the inode bitmaps to disk 
	// Since the all operations on disk should be of BLOCK_SIZE and our bitmap is not that big enough we copy it in a buffer of size BLOCK_SIZE and then write to the disk and the desired block num location
	// write inode_bitmap buffer to disk
	if (bio_write(INODE_BITMAP_BLKNO, inode_bitmap_buffer) < 0) {
		perror("inode_bitmap_buffer NOT able to write to disk during initialisation(rufs_mkfs)");
		exit(EXIT_FAILURE);
	}

	// initialize data block bitmap

	// We know already occupied data blocks during superblock initialisation
	// DATA BLOCK 0 = SUPERBLOCK
	// DATA BLOCK 1 = INODE_BITMAP_BLOCK
	// DATA BLOCK 2 = DATA_BLOCK_BITMAP_BLOCK
	// DATA BLOCK 3 = INODE_BLOCKS
	// DATA BLOCK 67 = DATA_BLOCKS
	memset(db_bitmap_buffer, 0, BLOCK_SIZE);
	for (int i = 0; i < DATA_BLOCK_START; i++) {
        set_bitmap(db_bitmap_buffer, i); 
	}
	// write db_bitmap buffer to disk
	if (bio_write(DB_BITMAP_BLKNO, db_bitmap_buffer) < 0) {
		perror("db_bitmap_buffer NOT able to write to disk during initialisation(rufs_mkfs)");
		exit(EXIT_FAILURE);
	}

	
	// we had assigned the first node as root node in the bitmap 
	// Initialise the first node as root node. Steps to follow:
	// 1. create a in-memory copy of the root inode.
	static struct inode root_inode;
	memset(&root_inode, 0, sizeof(root_inode));
    root_inode.ino = 0;
    root_inode.valid = 1;
    root_inode.type = TYPE_DIR;
    root_inode.link = 2;  // For . and ..
    root_inode.vstat.st_mode = S_IFDIR | 0755;
    root_inode.vstat.st_nlink = 2;
    root_inode.vstat.st_uid = getuid();
    root_inode.vstat.st_gid = getgid();
    root_inode.vstat.st_blksize = BLOCK_SIZE;
    root_inode.vstat.st_ctime = root_inode.vstat.st_atime = root_inode.vstat.st_mtime = time(NULL);

	for(int i=0;i<16;i++){
		root_inode.direct_ptr[i]=0;
	}

	for(int i=0;i<8;i++){
		root_inode.indirect_ptr[i]=0;
	}

	// 2. in order to write it to the disk 
	// Create an in-memory copy(i.e data block buffer) of the data block that stores the inode (i.e INODE_BLOCK_START)
	// update the buffer(i.e update the inode that it stores)
	//  write that buffer to the disk at the block num which stores the first inode (i.e INODE_BLOCK_START)
	// Sine we will have to repeat the task of updating inodes a lot we have already been given a helper function (i.e writei)
	if (writei(0, &root_inode) < 0) {
		perror("root_inode NOT updated on disk during initialisation(rufs_mkfs)");
		exit(EXIT_FAILURE);
	}

	return 0;
}

/* 
 * FUSE file operations
 */
static void *rufs_init(struct fuse_conn_info *conn) {

	// Step 1a: If disk file is not found, call mkfs
	int diskfile = -1;
	diskfile = open(diskfile_path, O_RDWR, S_IRUSR | S_IWUSR);

	if (diskfile < 0) {
		if (rufs_mkfs() != 0) {
			exit(EXIT_FAILURE);
		}
	}

	// Step 1b: If disk file is found, just initialize in-memory data structures
	// and read superblock from disk

	else {
		if (dev_open(diskfile_path) < 0) {
			
			exit(EXIT_FAILURE);
		}

		// Superblock
		if (bio_read(0, super_block_buffer) < 0) {
			
			exit(EXIT_FAILURE);
		}
		memcpy(&super_block, super_block_buffer, sizeof(struct superblock));

		// Inode bitmap
		if (bio_read(1, inode_bitmap_buffer) < 0) {
			
			exit(EXIT_FAILURE);
		}

		// Data block bitmap
		if (bio_read(2, db_bitmap_buffer) < 0) {
			exit(EXIT_FAILURE);
		}
	}
	return NULL;
}

static void rufs_destroy(void *userdata) {

	// Step 1: De-allocate in-memory data structures
	// Step 2: Close diskfile
	dev_close();


}

static int rufs_getattr(const char *path, struct stat *stbuf) {
	// printf("In rufs_getattr \n");
    // Step 1: call get_node_by_path() to get inode from path
    static struct inode inode;
    unsigned char *inode_ptr = (unsigned char *)&inode;
    for (size_t i = 0; i < sizeof(struct inode); ++i) {
        inode_ptr[i] = 0;
    }

    int retstat = get_node_by_path(path, 0, &inode);

    if (retstat < 0) {
        return retstat;
    }

    // Step 2: fill attribute of file into stbuf from inode
    memcpy(stbuf, &(inode.vstat), sizeof(struct stat));

    return 0;
}


static int rufs_opendir(const char *path, struct fuse_file_info *fi) {

	// Step 1: Call get_node_by_path() to get inode from path
    static char dup_path[PATH_MAX]; // Static array for path duplication

    // Check for buffer overflow
    if (strlen(path) >= PATH_MAX) {
        fprintf(stderr, "Error: Path is too long - rufs_opendir\n");
        return -ENAMETOOLONG;
    }

    // Copy the path into dup_path
    strncpy(dup_path, path, PATH_MAX);
    dup_path[PATH_MAX - 1] = '\0'; // Ensure null termination

    struct inode inode;
    int retstat = get_node_by_path(dup_path, 0, &inode); // inode number for root is 0

    if (retstat < 0) {
        return retstat;
    }

    return retstat;
}

static int rufs_readdir(const char *path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    struct inode inode;
    int retstat = get_node_by_path(path, 0, &inode); // inode number for root is 0
    if (retstat < 0) {
        return retstat;
    }

    if (inode.type != TYPE_DIR) {
        return -ENOTDIR;
    }

    static char rd_buf[BLOCK_SIZE];
    static struct dirent cur_dirent;

	int b = 0, off = 0;

    while (b < 16 && inode.direct_ptr[b] != 0) {
        retstat = bio_read(inode.direct_ptr[b], rd_buf);
        if (retstat < 0) {
            return retstat;
        }

        off = 0;
        while (off < dirent_pblk) {
            memcpy(&cur_dirent, rd_buf + (off * sizeof(struct dirent)), sizeof(struct dirent));
            if (cur_dirent.valid) {
                filler(buffer, cur_dirent.name, NULL, 0);
            }
            off++;
        }
        b++;
    }

    return 0;
}

void get_parent_path(const char *path, char *parent) {
    strcpy(parent, path);
    char *last_slash = strrchr(parent, '/');
    if (last_slash != NULL) {
        *last_slash = '\0';  // Cut off the part after the last '/'
    }
}

void get_target_name(const char *path, char *target) {
    const char *last_slash = strrchr(path, '/');
    if (last_slash != NULL) {
        strcpy(target, last_slash + 1);  // Copy the part after the last '/'
    } else {
        strcpy(target, path);  // The path is already the target name
    }
}

static int rufs_mkdir(const char *path, mode_t mode) {
    static char parent[PATH_MAX], target[PATH_MAX];
    get_parent_path(path, parent);
    get_target_name(path, target);

    static struct inode parent_inode;
    int retstat = get_node_by_path(parent, 0, &parent_inode);
    if (retstat < 0) return retstat;

    uint16_t new_ino = get_avail_ino();
    if (new_ino < 0) return new_ino;

    retstat = dir_add(parent_inode, new_ino, target, strlen(target));
    if (retstat < 0) return retstat;

    static struct inode target_inode;
    memset(&target_inode, 0, sizeof(struct inode));
    target_inode.ino = new_ino;
    target_inode.valid = 1;
    target_inode.type = TYPE_DIR;
    target_inode.link = 2;  // for . and ..
    target_inode.vstat.st_mode = S_IFDIR | mode;
    target_inode.vstat.st_nlink = 2;
    target_inode.vstat.st_uid = getuid();
    target_inode.vstat.st_gid = getgid();
    target_inode.vstat.st_blksize = BLOCK_SIZE;
    target_inode.vstat.st_ctime = target_inode.vstat.st_atime = target_inode.vstat.st_mtime = time(NULL);

    retstat = writei(new_ino, &target_inode);
    if (retstat < 0) return retstat;

    return 0;
}

static int rufs_rmdir(const char *path) {

	// Step 1: Use dirname() and basename() to separate parent directory path and target directory name

	// Step 2: Call get_node_by_path() to get inode of target directory

	// Step 3: Clear data block bitmap of target directory

	// Step 4: Clear inode bitmap and its data block

	// Step 5: Call get_node_by_path() to get inode of parent directory

	// Step 6: Call dir_remove() to remove directory entry of target directory in its parent directory

	return 0;
}

static int rufs_releasedir(const char *path, struct fuse_file_info *fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_create(const char *path, mode_t mode, struct fuse_file_info *fi) {

	// Step 1: Separate parent directory path and target file name
    static char parent_path[PATH_MAX];
    static char target_file_name[PATH_MAX];

    get_parent_path(path, parent_path);
    get_target_name(path, target_file_name);

	// Step 2: Call get_node_by_path() to get inode of parent directory
    static struct inode parent_inode;
    int retstat = get_node_by_path(parent_path, 0, &parent_inode);
    if (retstat < 0) {
        return retstat;
    }

    int avail_ino = get_avail_ino();
    if (avail_ino == -ENOSPC) {
        return avail_ino;
    }
	// printf("avail_ino: %d \n", avail_ino);

    retstat = dir_add(parent_inode, avail_ino, target_file_name, strlen(target_file_name));
    if (retstat < 0) {
        return retstat;
    }

    static struct inode new_inode;
    memset(&new_inode, 0, sizeof(struct inode));
    new_inode.ino = avail_ino;
    new_inode.valid = 1;
    new_inode.type = TYPE_FILE;
    new_inode.link = 1;
    new_inode.vstat.st_mode = S_IFREG | mode;
    new_inode.vstat.st_nlink = 1;
    new_inode.vstat.st_uid = getuid();
    new_inode.vstat.st_gid = getgid();
    new_inode.vstat.st_blksize = BLOCK_SIZE;
    new_inode.vstat.st_blocks = 0;
    time(&new_inode.vstat.st_atime);
    time(&new_inode.vstat.st_mtime);
    time(&new_inode.vstat.st_ctime);

	for (int i = 0; i < 16; i++) {
        new_inode.direct_ptr[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        new_inode.indirect_ptr[i] = 0;
    }

    retstat = writei(avail_ino, &new_inode);
    if (retstat < 0) {
        return retstat;
    }

    return 0;
}

static int rufs_open(const char *path, struct fuse_file_info *fi) {
    static struct inode temp_inode;
    int retstat = get_node_by_path(path, 0, &temp_inode);

    if (retstat < 0) {
        return retstat;
    }

    if (temp_inode.valid != 1 || temp_inode.type != TYPE_FILE || temp_inode.ino >= MAX_INUM) {
        return -EINVAL; // Not a valid file type or invalid inode number
    }

    return 0;
}

static int rufs_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi) {
    static struct inode temp_inode;
    int retstat = get_node_by_path(path, 0, &temp_inode);
    if (retstat < 0) {
        return retstat;
    }

    int bytes_written = 0;
    static char data_block[BLOCK_SIZE];

    while (bytes_written < size) {
        int block_num = (offset + bytes_written) / BLOCK_SIZE;
        int block_offset = (offset + bytes_written) % BLOCK_SIZE;
        int block_to_write = super_block.d_start_blk + temp_inode.direct_ptr[block_num];

        if (temp_inode.direct_ptr[block_num] == 0) {
            int new_data_block = get_avail_blkno();
            if (new_data_block < 0) return new_data_block;
            temp_inode.direct_ptr[block_num] = new_data_block;
            block_to_write = super_block.d_start_blk + new_data_block;
        }

        int bytes_to_write = BLOCK_SIZE - block_offset;
        if (bytes_to_write > size - bytes_written) {			//this is more or less checking if we can write the full block or not
            bytes_to_write = size - bytes_written;
        }

        if (bio_read(block_to_write, data_block) < 0) {
            return -EIO;
        }

        memcpy(data_block + block_offset, buffer + bytes_written, bytes_to_write);

        if (bio_write(block_to_write, data_block) < 0) {
            return -EIO;
        }

        bytes_written += bytes_to_write;
    }

    time(&(temp_inode.vstat.st_atime));
    time(&(temp_inode.vstat.st_mtime));
    temp_inode.vstat.st_size = offset + bytes_written;
    writei(temp_inode.ino, &temp_inode);

    return bytes_written;
}

static int rufs_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi) {
    static struct inode temp_inode;
    int retstat = get_node_by_path(path, 0, &temp_inode);
    if (retstat < 0) {
        return retstat;
    }

    int bytes_read = 0;
    static char data_block[BLOCK_SIZE];

    while (bytes_read < size) {
        int block_num = (offset + bytes_read) / BLOCK_SIZE;
        int block_offset = (offset + bytes_read) % BLOCK_SIZE;
        int block_to_read = super_block.d_start_blk + temp_inode.direct_ptr[block_num];

        if (temp_inode.direct_ptr[block_num] == 0) {
            // No more data to read
            break;
        }

        if (bio_read(block_to_read, data_block) < 0) {
            return -EIO;
        }

        int bytes_to_read = BLOCK_SIZE - block_offset;
        if (bytes_to_read > size - bytes_read) {
            bytes_to_read = size - bytes_read;
        }

        memcpy(buffer + bytes_read, data_block + block_offset, bytes_to_read);
        bytes_read += bytes_to_read;
    }

    // Update the inode access time
    time(&(temp_inode.vstat.st_atime));
    writei(temp_inode.ino, &temp_inode);

    return bytes_read;
}


static int rufs_unlink(const char *path) {

	// Step 1: Use dirname() and basename() to separate parent directory path and target file name

	// Step 2: Call get_node_by_path() to get inode of target file

	// Step 3: Clear data block bitmap of target file

	// Step 4: Clear inode bitmap and its data block
    
	// Step 5: Call get_node_by_path() to get inode of parent directory

	// Step 6: Call dir_remove() to remove directory entry of target file in its parent directory
	return 0;
}

static int rufs_truncate(const char *path, off_t size) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_release(const char *path, struct fuse_file_info *fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
	return 0;
}

static int rufs_flush(const char * path, struct fuse_file_info * fi) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}

static int rufs_utimens(const char *path, const struct timespec tv[2]) {
	// For this project, you don't need to fill this function
	// But DO NOT DELETE IT!
    return 0;
}


static struct fuse_operations rufs_ope = {
	.init		= rufs_init,
	.destroy	= rufs_destroy,

	.getattr	= rufs_getattr,
	.readdir	= rufs_readdir,
	.opendir	= rufs_opendir,
	.releasedir	= rufs_releasedir,
	.mkdir		= rufs_mkdir,
	.rmdir		= rufs_rmdir,

	.create		= rufs_create,
	.open		= rufs_open,
	.read 		= rufs_read,
	.write		= rufs_write,
	.unlink		= rufs_unlink,

	.truncate   = rufs_truncate,
	.flush      = rufs_flush,
	.utimens    = rufs_utimens,
	.release	= rufs_release
};


int main(int argc, char *argv[]) {
	int fuse_stat;

	getcwd(diskfile_path, PATH_MAX);
	strcat(diskfile_path, "/DISKFILE");

	fuse_stat = fuse_main(argc, argv, &rufs_ope, NULL);

	return fuse_stat;
}

// int dir_remove(struct inode dir_inode, const char *fname, size_t name_len) {

// 	// // Step 1: Read dir_inode's data block and checks each directory entry of dir_inode
//     // int retstat = 0;
//     // char curr_dir_block[BLOCK_SIZE];
    
//     // int block = 0;
//     // while (block < 16 && dir_inode.direct_ptr[block] != 0) { 
//     //     // Read the directory's data block
//     //     retstat = bio_read(dir_inode.direct_ptr[block], curr_dir_block);
//     //     if (retstat < 0) {
//     //         return retstat;
//     //     }

//     //     // Check each directory entry within the block
//     //     int i = 0;
//     //     while (i < BLOCK_SIZE / sizeof(struct dirent)) {
//     //         struct dirent *cur_dirent = (struct dirent *)(curr_dir_block + (i * sizeof(struct dirent)));
//     //         // Step 2: Check if fname exist
//     //         if ((cur_dirent->valid == 1) && (strncmp(cur_dirent->name, fname, name_len) == 0)) {
//     //             // Step 3: If exist, then remove it from dir_inode's data block and write to disk
//     //             cur_dirent->valid = 0;
//     //             retstat = bio_write(dir_inode.direct_ptr[0], curr_dir_block);
//     //             if (retstat < 0) {
//     //                 return retstat;
//     //             }
//     //             return 0; 
//     //         }

//     //         i++;
//     //     }

//     //     block++;
//     // }
// 	return 0;
// }

// static int rufs_rmdir(const char *path) {

// 	// // Step 1: Use dirname() and basename() to separate parent directory path and target directory name
//     // static char parent_path[PATH_MAX], target_name[PATH_MAX], target_dir_path[PATH_MAX];

//     // // Check for buffer overflow
//     // if (strlen(path) >= PATH_MAX) {
//     //     fprintf(stderr, "Error: Path is too long in rufs_opendir\n");
//     //     return -1;
//     // }

//     // get_parent_path(path, parent_path);
//     // get_target_name(path, target_name);

// 	// // Step 2: Call get_node_by_path() to get inode of target directory
//     // // Copy the path into target_dir_path
//     // strncpy(target_dir_path, path, PATH_MAX);
//     // target_dir_path[PATH_MAX - 1] = '\0'; // Ensure null termination

//     // static struct inode target_dir_inode;
//     // int target_inode_lookup_result = get_node_by_path(target_dir_path, 0, &target_dir_inode);
//     // if (target_inode_lookup_result < 0) {
//     //     return target_inode_lookup_result;
//     // }

// 	// // Step 3: Clear data block bitmap of target directory
//     // int block_index;
//     // for (block_index = 0; block_index < 16 && target_dir_inode.direct_ptr[block_index] != 0; block_index++) {
//     //     unset_bitmap(db_bitmap_buffer, target_dir_inode.direct_ptr[block_index]);
//     // }

// 	// // Step 4: Clear inode bitmap and its data block
//     // unset_bitmap(inode_bitmap_buffer, target_dir_inode.ino);

// 	// // Step 5: Call get_node_by_path() to get inode of parent directory
//     // static struct inode parent_dir_inode;
//     // int parent_inode_lookup_result = get_node_by_path(parent_path, 0, &parent_dir_inode);
//     // if (parent_inode_lookup_result < 0) {
//     //     return parent_inode_lookup_result;
//     // }

// 	// // Step 6: Call dir_remove() to remove directory entry of target directory in its parent directory
//     // int result = dir_remove(parent_dir_inode, target_name, strlen(target_name));
//     // if (result < 0){
//     //     return result;
//     // }


// 	return 0;
// }

	// if ((ret = rmdir(TESTDIR "/files")) < 0) {
	// 	perror("rmdir");
	// 	printf("TEST 8: failure. %s \n", TESTDIR "/files");
	// 	exit(1);
	// }
	// printf("TEST 8: Directory removed success \n");