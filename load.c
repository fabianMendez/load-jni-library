#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>

typedef char* (*some_function)();


int main(int argc, char **argv) {
	if (argc == 1) {
		printf("Usage: %s <shared_library>\n", argv[0]);
		return 1;
	}

	char* path = argv[1];

	if (access(path, R_OK) != 0) {
		printf("[!] Error reading library '%s': %s\n", path, strerror(errno));
		return 1;
	}

	some_function func;


	printf("[*] Loading library from: %s\n", path);

	void* handle = dlopen(path, RTLD_NOW);

	*(char**)(&func) = dlsym(handle, "some_function");

	printf("func() -> %s\n", func());

	dlclose(handle);

	return 0;
}
