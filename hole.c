#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file_with_hole.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    write(fd, "Start", 5);

    lseek(fd, 1024, SEEK_CUR);

    write(fd, "End", 3);

    close(fd);

    printf("File with a hole created: file_with_hole.txt\n");
    return 0;
}

