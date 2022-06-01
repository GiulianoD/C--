void pause(){
    fflush(stdin);
    printf("System paused. Press enter to continue.");
    getchar();
    fflush(stdin);
}

void open_chrome(char *lnk){
    char *cmd;
    strcpy(cmd, START_CHORME_);
    strcat(cmd, lnk);
    system(cmd);
}
