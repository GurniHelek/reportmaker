/*
 * By Kovalenko Vlad
 */
#include "reportmaker.h"

int prepare_docx2read(const char* docx_file_name)
{
    char cmd[512] = {0};

    // 1 Rename docx to zip
    sprintf(cmd, "cp %s.docx %s.zip", docx_file_name, docx_file_name);
    system(cmd);

    // 2 Unzip archive
    sprintf(cmd, "unzip %s.zip -d %s", docx_file_name, docx_file_name);
    system(cmd);

    // 3 Read from archive /word/document.xml
    sprintf(cmd, "cat %s/word/document.xml", docx_file_name);
    system(cmd);

    return 0;
}


