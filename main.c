/*
 * @author: Vlad Kovalenko
 */

#include "reportmaker.h"

int main()
{
    const char* file = "/home/vkovalenko/Workspace/reportmaker/docx/tza_IssueReport_template";
    const char* new_file = "/home/vkovalenko/Workspace/reportmaker/docx/test";

    printf("Extract from docx...\n");
    extract_docx(file);

    printf("Restore docx...\n");
    restore_docx(file, new_file);

    return(0);
}
