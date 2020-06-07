#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(float features[161]) {

    int classes[2];
        
    if (features[130] <= 0.5) {
        if (features[61] <= 0.5) {
            if (features[140] <= 0.5) {
                if (features[159] <= 0.5) {
                    if (features[151] <= 0.5) {
                        if (features[160] <= 0.5) {
                            if (features[70] <= 0.5) {
                                if (features[135] <= 0.5) {
                                    if (features[156] <= 0.5) {
                                        classes[0] = 198; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[64] <= 0.5) {
                                            if (features[79] <= 0.5) {
                                                if (features[102] <= 0.5) {
                                                    if (features[27] <= 0.5) {
                                                        if (features[131] <= 0.5) {
                                                            if (features[23] <= 0.5) {
                                                                classes[0] = 16806; 
                                                                classes[1] = 2619; 
                                                            } else {
                                                                classes[0] = 11; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 25; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 2; 
                                                    }
                                                } else {
                                                    classes[0] = 38; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[131] <= 0.5) {
                                                    if (features[113] <= 0.5) {
                                                        if (features[12] <= 0.5) {
                                                            if (features[13] <= 0.5) {
                                                                classes[0] = 1; 
                                                                classes[1] = 1; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 1; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 3; 
                                                    }
                                                } else {
                                                    classes[0] = 2; 
                                                    classes[1] = 0; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 6; 
                                        }
                                    }
                                } else {
                                    classes[0] = 300; 
                                    classes[1] = 0; 
                                }
                            } else {
                                if (features[74] <= 0.5) {
                                    if (features[27] <= 0.5) {
                                        if (features[98] <= 0.5) {
                                            if (features[35] <= 0.5) {
                                                if (features[26] <= 0.5) {
                                                    classes[0] = 4; 
                                                    classes[1] = 13; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 2; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 4; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 10; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 14; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 17; 
                                }
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 82; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 99; 
                    }
                } else {
                    if (features[0] <= 0.5) {
                        if (features[48] <= 0.5) {
                            if (features[155] <= 0.5) {
                                if (features[79] <= 0.5) {
                                    if (features[135] <= 0.5) {
                                        if (features[34] <= 0.5) {
                                            if (features[21] <= 0.5) {
                                                if (features[70] <= 0.5) {
                                                    classes[0] = 892; 
                                                    classes[1] = 723; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 1; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 12; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 20; 
                                        }
                                    } else {
                                        classes[0] = 36; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 31; 
                                }
                            } else {
                                classes[0] = 0; 
                                classes[1] = 67; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 115; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 170; 
                    }
                }
            } else {
                if (features[135] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 1491; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[116] <= 0.5) {
                if (features[45] <= 0.5) {
                    if (features[141] <= 0.5) {
                        if (features[135] <= 0.5) {
                            if (features[77] <= 0.5) {
                                if (features[79] <= 0.5) {
                                    if (features[0] <= 0.5) {
                                        if (features[5] <= 0.5) {
                                            if (features[48] <= 0.5) {
                                                if (features[11] <= 0.5) {
                                                    if (features[30] <= 0.5) {
                                                        if (features[145] <= 0.5) {
                                                            if (features[137] <= 0.5) {
                                                                classes[0] = 3725; 
                                                                classes[1] = 4875; 
                                                            } else {
                                                                classes[0] = 20; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 46; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 55; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 95; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 107; 
                                            }
                                        } else {
                                            if (features[120] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 127; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 138; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 147; 
                                }
                            } else {
                                classes[0] = 0; 
                                classes[1] = 163; 
                            }
                        } else {
                            if (features[11] <= 0.5) {
                                if (features[60] <= 0.5) {
                                    if (features[79] <= 0.5) {
                                        if (features[70] <= 0.5) {
                                            if (features[156] <= 0.5) {
                                                if (features[134] <= 0.5) {
                                                    if (features[136] <= 0.5) {
                                                        if (features[23] <= 0.5) {
                                                            if (features[150] <= 0.5) {
                                                                classes[0] = 138; 
                                                                classes[1] = 109; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 7; 
                                                            }
                                                        } else {
                                                            classes[0] = 12; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 37; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    classes[0] = 217; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[108] <= 0.5) {
                                                    if (features[150] <= 0.5) {
                                                        if (features[136] <= 0.5) {
                                                            if (features[134] <= 0.5) {
                                                                classes[0] = 1676; 
                                                                classes[1] = 122; 
                                                            } else {
                                                                classes[0] = 148; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 4; 
                                                        }
                                                    } else {
                                                        if (features[134] <= 0.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 5; 
                                                        } else {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 6; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 64; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 131; 
                                    }
                                } else {
                                    if (features[51] <= 0.5) {
                                        if (features[14] <= 0.5) {
                                            if (features[76] <= 0.5) {
                                                if (features[108] <= 0.5) {
                                                    if (features[68] <= 0.5) {
                                                        if (features[5] <= 0.5) {
                                                            if (features[77] <= 0.5) {
                                                                classes[0] = 117; 
                                                                classes[1] = 218; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 6; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 7; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 13; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 22; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 27; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 41; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 123; 
                                    }
                                }
                            } else {
                                if (features[101] <= 0.5) {
                                    if (features[133] <= 0.5) {
                                        if (features[115] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 422; 
                                        } else {
                                            if (features[79] <= 0.5) {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            }
                                        }
                                    } else {
                                        if (features[23] <= 0.5) {
                                            if (features[156] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 7; 
                                            } else {
                                                if (features[102] <= 0.5) {
                                                    if (features[91] <= 0.5) {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 2; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 2; 
                                            classes[1] = 0; 
                                        }
                                    }
                                } else {
                                    classes[0] = 3; 
                                    classes[1] = 0; 
                                }
                            }
                        }
                    } else {
                        if (features[82] <= 0.5) {
                            if (features[23] <= 0.5) {
                                if (features[138] <= 0.5) {
                                    if (features[9] <= 0.5) {
                                        if (features[108] <= 0.5) {
                                            if (features[133] <= 0.5) {
                                                if (features[134] <= 0.5) {
                                                    if (features[76] <= 0.5) {
                                                        if (features[79] <= 0.5) {
                                                            if (features[60] <= 0.5) {
                                                                classes[0] = 1; 
                                                                classes[1] = 3; 
                                                            } else {
                                                                classes[0] = 5; 
                                                                classes[1] = 40; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 13; 
                                                        }
                                                    } else {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 34; 
                                                }
                                            } else {
                                                if (features[70] <= 0.5) {
                                                    if (features[79] <= 0.5) {
                                                        if (features[123] <= 0.5) {
                                                            classes[0] = 7; 
                                                            classes[1] = 0; 
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 1; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 4; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 9; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 69; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 255; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1062; 
                                }
                            } else {
                                classes[0] = 6; 
                                classes[1] = 0; 
                            }
                        } else {
                            if (features[33] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 17; 
                            } else {
                                classes[0] = 17; 
                                classes[1] = 0; 
                            }
                        }
                    }
                } else {
                    if (features[136] <= 0.5) {
                        if (features[133] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 1438; 
                        } else {
                            if (features[27] <= 0.5) {
                                classes[0] = 6; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 209; 
                            }
                        }
                    } else {
                        classes[0] = 6; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[70] <= 0.5) {
                    if (features[104] <= 0.5) {
                        if (features[96] <= 0.5) {
                            if (features[88] <= 0.5) {
                                if (features[60] <= 0.5) {
                                    classes[0] = 1391; 
                                    classes[1] = 0; 
                                } else {
                                    if (features[135] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    } else {
                                        classes[0] = 159; 
                                        classes[1] = 0; 
                                    }
                                }
                            } else {
                                classes[0] = 0; 
                                classes[1] = 1; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    } else {
                        classes[0] = 0; 
                        classes[1] = 5; 
                    }
                } else {
                    classes[0] = 0; 
                    classes[1] = 10; 
                }
            }
        }
    } else {
        if (features[70] <= 0.5) {
            if (features[79] <= 0.5) {
                classes[0] = 21900; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 1; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 6; 
        }
    }

    int index = 0;
    for (int i = 0; i < 2; i++) {
        index = classes[i] > classes[index] ? i : index;
    }
    return index;
}

#define N_FEAFURES 161
#define STR(s) #s
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int l_predict(lua_State *L) {
    int nargs = lua_gettop(L);
    if (nargs < 1) {
        lua_pushstring(L, "Missing positional argument: features (table)");
        lua_error(L);
    }

    // ignore other arguments
    lua_settop(L, 1);

    luaL_checktype(L, 1, LUA_TTABLE);
    int input_table_length = lua_objlen(L, 1);
    printf("Input features: %d\n", input_table_length);

    if (input_table_length != N_FEAFURES) {
        lua_pushstring(L, "Wrong number of features (required " STR(N_FEAFURES) " features)");
        lua_error(L);
    }

    float features[N_FEAFURES];
    int i = 0;
    lua_pushnil(L);
    while (lua_next(L, 1) != 0) {
        features[i++] = luaL_checknumber(L, -1);
        lua_pop(L, 1);
    }

    int result = predict(features);
    lua_pushnumber(L, result);
    return 1;
}

static const struct luaL_reg decision_tree[] = {
    { "predict", l_predict },
    { NULL, NULL }
};

int luaopen_decision_tree(lua_State *L) {
    luaL_register(L, "decision_tree", decision_tree);
    return 0;
}