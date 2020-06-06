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
                                        classes[0] = 185; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[64] <= 0.5) {
                                            if (features[79] <= 0.5) {
                                                if (features[102] <= 0.5) {
                                                    if (features[27] <= 0.5) {
                                                        if (features[131] <= 0.5) {
                                                            if (features[60] <= 0.5) {
                                                                classes[0] = 16761; 
                                                                classes[1] = 2619; 
                                                            } else {
                                                                classes[0] = 11; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 14; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 2; 
                                                    }
                                                } else {
                                                    classes[0] = 36; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[131] <= 0.5) {
                                                    if (features[113] <= 0.5) {
                                                        if (features[12] <= 0.5) {
                                                            if (features[38] <= 0.5) {
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
                                    classes[0] = 296; 
                                    classes[1] = 0; 
                                }
                            } else {
                                if (features[74] <= 0.5) {
                                    if (features[27] <= 0.5) {
                                        if (features[98] <= 0.5) {
                                            if (features[35] <= 0.5) {
                                                if (features[26] <= 0.5) {
                                                    classes[0] = 7; 
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
                            if (features[60] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 82; 
                            } else {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            }
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
                                        if (features[154] <= 0.5) {
                                            if (features[21] <= 0.5) {
                                                if (features[98] <= 0.5) {
                                                    classes[0] = 854; 
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
                                        classes[0] = 37; 
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
                classes[0] = 1; 
                classes[1] = 1491; 
            }
        } else {
            if (features[116] <= 0.5) {
                if (features[45] <= 0.5) {
                    if (features[141] <= 0.5) {
                        if (features[11] <= 0.5) {
                            if (features[135] <= 0.5) {
                                if (features[160] <= 0.5) {
                                    if (features[79] <= 0.5) {
                                        if (features[0] <= 0.5) {
                                            if (features[48] <= 0.5) {
                                                if (features[5] <= 0.5) {
                                                    if (features[155] <= 0.5) {
                                                        if (features[145] <= 0.5) {
                                                            if (features[136] <= 0.5) {
                                                                classes[0] = 3914; 
                                                                classes[1] = 4852; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 23; 
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
                                                    if (features[125] <= 0.5) {
                                                        if (features[60] <= 0.5) {
                                                            if (features[156] <= 0.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 51; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 52; 
                                                            }
                                                        } else {
                                                            if (features[93] <= 0.5) {
                                                                classes[0] = 3; 
                                                                classes[1] = 14; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 9; 
                                                            }
                                                        }
                                                    } else {
                                                        classes[0] = 2; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 107; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 138; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 146; 
                                    }
                                } else {
                                    if (features[60] <= 0.5) {
                                        classes[0] = 1; 
                                        classes[1] = 83; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 80; 
                                    }
                                }
                            } else {
                                if (features[60] <= 0.5) {
                                    if (features[79] <= 0.5) {
                                        if (features[70] <= 0.5) {
                                            if (features[134] <= 0.5) {
                                                if (features[156] <= 0.5) {
                                                    if (features[136] <= 0.5) {
                                                        if (features[150] <= 0.5) {
                                                            if (features[5] <= 0.5) {
                                                                classes[0] = 146; 
                                                                classes[1] = 105; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 4; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 7; 
                                                        }
                                                    } else {
                                                        classes[0] = 43; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    if (features[108] <= 0.5) {
                                                        if (features[150] <= 0.5) {
                                                            if (features[136] <= 0.5) {
                                                                classes[0] = 1580; 
                                                                classes[1] = 122; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 4; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 5; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 6; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 396; 
                                                classes[1] = 0; 
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
                                                    if (features[23] <= 0.5) {
                                                        if (features[68] <= 0.5) {
                                                            if (features[5] <= 0.5) {
                                                                classes[0] = 80; 
                                                                classes[1] = 224; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 7; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 13; 
                                                        }
                                                    } else {
                                                        classes[0] = 3; 
                                                        classes[1] = 0; 
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
                            }
                        } else {
                            if (features[115] <= 0.5) {
                                if (features[133] <= 0.5) {
                                    if (features[101] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 518; 
                                    } else {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    if (features[23] <= 0.5) {
                                        if (features[159] <= 0.5) {
                                            if (features[102] <= 0.5) {
                                                if (features[81] <= 0.5) {
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
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 7; 
                                        }
                                    } else {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    }
                                }
                            } else {
                                if (features[79] <= 0.5) {
                                    classes[0] = 2; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 2; 
                                }
                            }
                        }
                    } else {
                        if (features[138] <= 0.5) {
                            if (features[33] <= 0.5) {
                                if (features[23] <= 0.5) {
                                    if (features[81] <= 0.5) {
                                        if (features[9] <= 0.5) {
                                            if (features[16] <= 0.5) {
                                                if (features[108] <= 0.5) {
                                                    if (features[79] <= 0.5) {
                                                        if (features[60] <= 0.5) {
                                                            if (features[134] <= 0.5) {
                                                                classes[0] = 4; 
                                                                classes[1] = 3; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 18; 
                                                            }
                                                        } else {
                                                            if (features[133] <= 0.5) {
                                                                classes[0] = 1; 
                                                                classes[1] = 57; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 1; 
                                                            }
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 23; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 76; 
                                                }
                                            } else {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 253; 
                                        }
                                    } else {
                                        classes[0] = 3; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 9; 
                                    classes[1] = 0; 
                                }
                            } else {
                                if (features[147] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 10; 
                                } else {
                                    if (features[5] <= 0.5) {
                                        classes[0] = 19; 
                                        classes[1] = 0; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    }
                                }
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1065; 
                        }
                    }
                } else {
                    if (features[136] <= 0.5) {
                        if (features[133] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 1438; 
                        } else {
                            if (features[9] <= 0.5) {
                                classes[0] = 6; 
                                classes[1] = 0; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 209; 
                            }
                        }
                    } else {
                        classes[0] = 8; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[70] <= 0.5) {
                    if (features[104] <= 0.5) {
                        if (features[91] <= 0.5) {
                            if (features[96] <= 0.5) {
                                if (features[60] <= 0.5) {
                                    classes[0] = 1294; 
                                    classes[1] = 0; 
                                } else {
                                    if (features[135] <= 0.5) {
                                        if (features[141] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 1; 
                                        } else {
                                            classes[0] = 1; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        classes[0] = 158; 
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
                classes[0] = 22028; 
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

int main(int argc, const char * argv[]) {

    /* Features: */
    double features[argc-1];
    int i;
    for (i = 1; i < argc; i++) {
        features[i-1] = atof(argv[i]);
    }

    /* Prediction: */
    printf("%d", predict(features));
    return 0;

}