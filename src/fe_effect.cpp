#include "fe/fe_effect.h"
#include "fe/fe_node.h"
#include <stdlib.h>

fe_node* fe_effect_find_node(const fe_effect* ef, int id)
{
    for (int i = 0; i < ef->num; ++i)
    {
        fe_node* node = ef->nodes[i];
        if (node->id == id)
            return node;
    }
    return 0;
}

fe_node* fe_effect_find_node_by_type(const fe_effect* ef, int tp)
{
    for (int i = 0; i < ef->num; ++i)
    {
        fe_node* node = ef->nodes[i];
        if (node->type == tp)
            return node;
    }
    return 0;
}

fe_node* fe_effect_get_node(const fe_effect* ef, int i)
{
    return ef->nodes[i];
}

const char* fe_effect_get_name(const fe_effect* ef)
{
    return ef->id;
}

void fe_effect_free(fe_effect* effect)
{
    for (int i = 0; i < effect->num; ++i)
    {
        free(effect->nodes[i]);
    }

    free(effect->nodes);
}