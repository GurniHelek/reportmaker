/*
 * @author: Vlad Kovalenko
 */
#include "reportmaker.h"

#define DOCUMENT_TXT_CONTAINER  "word/document.xml"

/*
 * docx file is zip archive with specific context.
 * So for getting text info from it you need rename .docx to .zip and simply extract its context
 * Text will be in extracted /word/document.xml between xml tegs <w:t> </w:t>
 */

int extract_docx(const char* docx_file_name)
{
    char cmd[512] = {0};

    // Rename docx to zip
    sprintf(cmd, "cp -f %s.docx %s.zip", docx_file_name, docx_file_name);
    system(cmd);

    // Unzip archive
    sprintf(cmd, "unzip  %s.zip -d %s >> /dev/null", docx_file_name, docx_file_name);
    system(cmd);

    // Remove temporary archive
    sprintf(cmd, "rm -f %s.zip", docx_file_name);
    system(cmd);

    return 0;
}

/*
 * TODO: parse document.xml to find all text between <w:t> </w:t> and replace them
 */

/*
 * To restore docx from unziped directory you have to zip ONLY context of this directory
 * and simply rename .zip to .docx
 */

int restore_docx(const char* extract_docx_path, const char* new_docx_file)
{
    char cmd[512] = {0};

    // Restore docx from directory with docx context
    sprintf(cmd, "cd %s && zip -r %s * >> /dev/null", extract_docx_path, new_docx_file);
    system(cmd);

    // Rename docx to zip
    sprintf(cmd, "cp -f %s.zip %s.docx", new_docx_file, new_docx_file);
    system(cmd);

    // Remove temporary directory and zip
    sprintf(cmd, "rm -rf %s", extract_docx_path);
    system(cmd);
    sprintf(cmd, "rm -r %s.zip", new_docx_file);
    system(cmd);

    return 0;
}
