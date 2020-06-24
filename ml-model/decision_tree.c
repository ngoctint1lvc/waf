#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(float features[161]) {

    int classes[2];
        
    if (features[130] <= 0.5) {
        if (features[159] <= 0.5) {
            if (features[140] <= 0.5) {
                if (features[61] <= 0.5) {
                    if (features[151] <= 0.5) {
                        if (features[77] <= 0.5) {
                            if (features[135] <= 0.5) {
                                if (features[70] <= 0.5) {
                                    if (features[156] <= 0.5) {
                                        classes[0] = 276; 
                                        classes[1] = 0; 
                                    } else {
                                        if (features[147] <= 0.5) {
                                            if (features[64] <= 0.5) {
                                                if (features[79] <= 0.5) {
                                                    if (features[131] <= 0.5) {
                                                        if (features[23] <= 0.5) {
                                                            if (features[27] <= 0.5) {
                                                                classes[0] = 11363; 
                                                                classes[1] = 2619; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 2; 
                                                            }
                                                        } else {
                                                            classes[0] = 28; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 28; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    if (features[131] <= 0.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 6; 
                                                    } else {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 6; 
                                            }
                                        } else {
                                            classes[0] = 54; 
                                            classes[1] = 0; 
                                        }
                                    }
                                } else {
                                    if (features[74] <= 0.5) {
                                        if (features[27] <= 0.5) {
                                            if (features[98] <= 0.5) {
                                                if (features[35] <= 0.5) {
                                                    if (features[60] <= 0.5) {
                                                        classes[0] = 8; 
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
                                classes[0] = 462; 
                                classes[1] = 0; 
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
                    if (features[135] <= 0.5) {
                        if (features[116] <= 0.5) {
                            if (features[23] <= 0.5) {
                                if (features[45] <= 0.5) {
                                    if (features[156] <= 0.5) {
                                        if (features[60] <= 0.5) {
                                            classes[0] = 3; 
                                            classes[1] = 83; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 80; 
                                        }
                                    } else {
                                        if (features[5] <= 0.5) {
                                            if (features[11] <= 0.5) {
                                                if (features[62] <= 0.5) {
                                                    if (features[127] <= 0.5) {
                                                        if (features[8] <= 0.5) {
                                                            if (features[131] <= 0.5) {
                                                                classes[0] = 201; 
                                                                classes[1] = 1830; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 1; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 38; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 53; 
                                        }
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 217; 
                                }
                            } else {
                                classes[0] = 21; 
                                classes[1] = 0; 
                            }
                        } else {
                            if (features[70] <= 0.5) {
                                if (features[104] <= 0.5) {
                                    if (features[96] <= 0.5) {
                                        classes[0] = 36; 
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
                        }
                    } else {
                        if (features[102] <= 0.5) {
                            if (features[45] <= 0.5) {
                                if (features[35] <= 0.5) {
                                    if (features[42] <= 0.5) {
                                        if (features[70] <= 0.5) {
                                            if (features[11] <= 0.5) {
                                                if (features[91] <= 0.5) {
                                                    if (features[108] <= 0.5) {
                                                        if (features[79] <= 0.5) {
                                                            if (features[77] <= 0.5) {
                                                                classes[0] = 2928; 
                                                                classes[1] = 137; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 9; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 11; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 14; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 44; 
                                                }
                                            } else {
                                                if (features[133] <= 0.5) {
                                                    if (features[101] <= 0.5) {
                                                        if (features[23] <= 0.5) {
                                                            if (features[134] <= 0.5) {
                                                                classes[0] = 3; 
                                                                classes[1] = 39; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 42; 
                                                            }
                                                        } else {
                                                            classes[0] = 2; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        classes[0] = 3; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    if (features[91] <= 0.5) {
                                                        classes[0] = 10; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 1; 
                                                    }
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 75; 
                                        }
                                    } else {
                                        if (features[116] <= 0.5) {
                                            if (features[136] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 117; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            classes[0] = 7; 
                                            classes[1] = 0; 
                                        }
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 164; 
                                }
                            } else {
                                if (features[116] <= 0.5) {
                                    if (features[136] <= 0.5) {
                                        if (features[133] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 336; 
                                        } else {
                                            if (features[27] <= 0.5) {
                                                classes[0] = 11; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 85; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 5; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 74; 
                                    classes[1] = 0; 
                                }
                            }
                        } else {
                            if (features[116] <= 0.5) {
                                if (features[82] <= 0.5) {
                                    if (features[51] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 413; 
                                    } else {
                                        if (features[33] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 65; 
                                        } else {
                                            if (features[11] <= 0.5) {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            }
                                        }
                                    }
                                } else {
                                    if (features[33] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 6; 
                                    } else {
                                        classes[0] = 9; 
                                        classes[1] = 0; 
                                    }
                                }
                            } else {
                                classes[0] = 10; 
                                classes[1] = 0; 
                            }
                        }
                    }
                }
            } else {
                if (features[61] <= 0.5) {
                    classes[0] = 1; 
                    classes[1] = 1491; 
                } else {
                    classes[0] = 1; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[116] <= 0.5) {
                if (features[82] <= 0.5) {
                    if (features[60] <= 0.5) {
                        if (features[136] <= 0.5) {
                            if (features[141] <= 0.5) {
                                if (features[61] <= 0.5) {
                                    if (features[135] <= 0.5) {
                                        if (features[0] <= 0.5) {
                                            if (features[48] <= 0.5) {
                                                if (features[30] <= 0.5) {
                                                    if (features[79] <= 0.5) {
                                                        if (features[154] <= 0.5) {
                                                            if (features[21] <= 0.5) {
                                                                classes[0] = 28; 
                                                                classes[1] = 724; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 12; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 20; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 29; 
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
                                    } else {
                                        if (features[7] <= 0.5) {
                                            classes[0] = 38; 
                                            classes[1] = 0; 
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 1; 
                                        }
                                    }
                                } else {
                                    if (features[79] <= 0.5) {
                                        if (features[11] <= 0.5) {
                                            if (features[135] <= 0.5) {
                                                if (features[0] <= 0.5) {
                                                    if (features[48] <= 0.5) {
                                                        if (features[137] <= 0.5) {
                                                            if (features[155] <= 0.5) {
                                                                classes[0] = 573; 
                                                                classes[1] = 1842; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 55; 
                                                            }
                                                        } else {
                                                            classes[0] = 13; 
                                                            classes[1] = 0; 
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
                                                if (features[134] <= 0.5) {
                                                    if (features[70] <= 0.5) {
                                                        if (features[150] <= 0.5) {
                                                            if (features[131] <= 0.5) {
                                                                classes[0] = 123; 
                                                                classes[1] = 105; 
                                                            } else {
                                                                classes[0] = 7; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 7; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 16; 
                                                    }
                                                } else {
                                                    if (features[147] <= 0.5) {
                                                        classes[0] = 53; 
                                                        classes[1] = 0; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 4; 
                                                    }
                                                }
                                            }
                                        } else {
                                            if (features[23] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 224; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 254; 
                                    }
                                }
                            } else {
                                if (features[134] <= 0.5) {
                                    if (features[79] <= 0.5) {
                                        if (features[135] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 1; 
                                        } else {
                                            classes[0] = 1; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 11; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 527; 
                                }
                            }
                        } else {
                            if (features[135] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 9; 
                            } else {
                                if (features[141] <= 0.5) {
                                    classes[0] = 74; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 2; 
                                }
                            }
                        }
                    } else {
                        if (features[137] <= 0.5) {
                            if (features[107] <= 0.5) {
                                if (features[45] <= 0.5) {
                                    if (features[135] <= 0.5) {
                                        if (features[141] <= 0.5) {
                                            if (features[131] <= 0.5) {
                                                if (features[5] <= 0.5) {
                                                    if (features[11] <= 0.5) {
                                                        if (features[79] <= 0.5) {
                                                            if (features[145] <= 0.5) {
                                                                classes[0] = 19; 
                                                                classes[1] = 1296; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 9; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 14; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 18; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 26; 
                                                }
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            if (features[131] <= 0.5) {
                                                classes[0] = 4; 
                                                classes[1] = 34; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 1; 
                                            }
                                        }
                                    } else {
                                        if (features[103] <= 0.5) {
                                            if (features[120] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 699; 
                                            } else {
                                                if (features[125] <= 0.5) {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 21; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 1; 
                                            classes[1] = 0; 
                                        }
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 964; 
                                }
                            } else {
                                if (features[81] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 4; 
                                } else {
                                    classes[0] = 5; 
                                    classes[1] = 0; 
                                }
                            }
                        } else {
                            classes[0] = 5; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[33] <= 0.5) {
                        if (features[9] <= 0.5) {
                            if (features[51] <= 0.5) {
                                classes[0] = 0; 
                                classes[1] = 2; 
                            } else {
                                classes[0] = 1; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 2; 
                        }
                    } else {
                        if (features[134] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        } else {
                            classes[0] = 307; 
                            classes[1] = 0; 
                        }
                    }
                }
            } else {
                if (features[60] <= 0.5) {
                    classes[0] = 1343; 
                    classes[1] = 0; 
                } else {
                    if (features[135] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 1; 
                    } else {
                        classes[0] = 9; 
                        classes[1] = 0; 
                    }
                }
            }
        }
    } else {
        if (features[70] <= 0.5) {
            if (features[79] <= 0.5) {
                classes[0] = 29755; 
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