#include "reportmaker.h"

int main()
{
    const char* file = "/home/vkovalenko/Workspace/reportmaker/docx/tza_IssueReport_template";

    printf("===== TEST =====\n");

    prepare_docx2read(file);

    return(0);
}
