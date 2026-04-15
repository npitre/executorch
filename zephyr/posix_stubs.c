/*
 * Copyright (c) 2026 BayLibre SAS
 * SPDX-License-Identifier: Apache-2.0
 *
 * Weak POSIX file I/O stubs for Zephyr baremetal.
 *
 * libstdc++ and picolibc's stdio (fopen, fdopen) reference these
 * syscalls transitively through C++ string/stream support.  On Zephyr
 * without a filesystem, provide weak stubs that return errors.
 */

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int __attribute__((weak)) open(const char *path, int flags, ...)
{
	(void)path; (void)flags;
	errno = ENOSYS;
	return -1;
}

ssize_t __attribute__((weak)) write(int fd, const void *buf, size_t count)
{
	(void)fd; (void)buf; (void)count;
	errno = ENOSYS;
	return -1;
}

ssize_t __attribute__((weak)) read(int fd, void *buf, size_t count)
{
	(void)fd; (void)buf; (void)count;
	errno = ENOSYS;
	return -1;
}

off_t __attribute__((weak)) lseek(int fd, off_t offset, int whence)
{
	(void)fd; (void)offset; (void)whence;
	errno = ENOSYS;
	return -1;
}

int __attribute__((weak)) close(int fd)
{
	(void)fd;
	errno = ENOSYS;
	return -1;
}

int __attribute__((weak)) fstat(int fd, struct stat *buf)
{
	(void)fd; (void)buf;
	errno = ENOSYS;
	return -1;
}
