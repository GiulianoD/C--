FILE *open_file(const char *path, const char *mode){
    FILE *f = fopen(path, mode);

    if (f) return f;
    fclose(f);

    printf("File not found. Please verify the path:\n%s\n\nError on line %d\n", path, __LINE__);
    pause();
    exit(0);
}

