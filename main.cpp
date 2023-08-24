#include <cstring>

extern "C" {
#include "tree_sitter/api.h"

TSLanguage *tree_sitter_cpp();

void actual_main()
{
    TSParser *parser = ts_parser_new();

    ts_parser_set_language(parser, tree_sitter_cpp());

    const char *source_code = "int main() { return 0; }";

    TSTree *tree = ts_parser_parse_string(
        parser,
        nullptr,
        source_code,
        strlen(source_code)
    );

    TSNode root_node = ts_tree_root_node(tree);

    char *string = ts_node_string(root_node);
    printf("Syntax tree: %s\n", string);

    free(string);
    ts_tree_delete(tree);
    ts_parser_delete(parser);
}
} // extern "C"

int main()
{
    actual_main();
    return 0;
}
