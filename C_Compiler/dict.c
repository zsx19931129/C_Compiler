//
//  dict.c
//  C_Compiler
//
//  Created by 张少雄 on 12/28/16.
//  Copyright © 2016 张少雄. All rights reserved.
//

#include <stdlib.h>
#include "C_Compiler.h"

Dict *make_dict() {
    Dict *r = malloc(sizeof(Dict));
    r->map = make_map();
    r->key = make_vector();
    return r;
}

void *dict_get(Dict *dict, char *key) {
    return map_get(dict->map, key);
}

void dict_put(Dict *dict, char *key, void *val) {
    map_put(dict->map, key, val);
    vec_push(dict->key, key);
}

Vector *dict_keys(Dict *dict) {
    return dict->key;
}
