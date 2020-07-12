#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(float features[159]) {

    int classes[2];
        
    if (features[128] <= 0.5) {
        if (features[157] <= 0.5) {
            if (features[138] <= 0.5) {
                if (features[45] <= 0.5) {
                    if (features[89] <= 0.5) {
                        if (features[11] <= 0.5) {
                            if (features[75] <= 0.5) {
                                if (features[133] <= 0.5) {
                                    if (features[149] <= 0.5) {
                                        if (features[68] <= 0.5) {
                                            if (features[154] <= 0.5) {
                                                classes[0] = 738; 
                                                classes[1] = 0; 
                                            } else {
                                                if (features[5] <= 0.5) {
                                                    if (features[143] <= 0.5) {
                                                        if (features[134] <= 0.5) {
                                                            if (features[106] <= 0.5) {
                                                                if (features[100] <= 0.5) {
                                                                    if (features[23] <= 0.5) {
                                                                        if (features[111] <= 0.5) {
                                                                            if (features[62] <= 0.5) {
                                                                                if (features[12] <= 0.5) {
                                                                                    classes[0] = 29149; 
                                                                                    classes[1] = 4489; 
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 5; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 6; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 7; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 112; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 119; 
                                                                    classes[1] = 0; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 9; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 10; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 16; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 48; 
                                                }
                                            }
                                        } else {
                                            if (features[72] <= 0.5) {
                                                if (features[27] <= 0.5) {
                                                    if (features[114] <= 0.5) {
                                                        if (features[108] <= 0.5) {
                                                            if (features[96] <= 0.5) {
                                                                if (features[26] <= 0.5) {
                                                                    if (features[35] <= 0.5) {
                                                                        if (features[14] <= 0.5) {
                                                                            if (features[83] <= 0.5) {
                                                                                classes[0] = 18; 
                                                                                classes[1] = 15; 
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
                                                                        classes[1] = 3; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 4; 
                                                                }
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
                                                        classes[1] = 10; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 12; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 15; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 104; 
                                    }
                                } else {
                                    if (features[35] <= 0.5) {
                                        if (features[106] <= 0.5) {
                                            if (features[68] <= 0.5) {
                                                if (features[77] <= 0.5) {
                                                    if (features[148] <= 0.5) {
                                                        if (features[132] <= 0.5) {
                                                            if (features[66] <= 0.5) {
                                                                if (features[102] <= 0.5) {
                                                                    if (features[114] <= 0.5) {
                                                                        if (features[134] <= 0.5) {
                                                                            if (features[62] <= 0.5) {
                                                                                if (features[33] <= 0.5) {
                                                                                    classes[0] = 6696; 
                                                                                    classes[1] = 111; 
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 2; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 2; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 4; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 671; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 2; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 2; 
                                                            }
                                                        } else {
                                                            if (features[69] <= 0.5) {
                                                                classes[0] = 1263; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 1; 
                                                            }
                                                        }
                                                    } else {
                                                        if (features[114] <= 0.5) {
                                                            if (features[23] <= 0.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 8; 
                                                            } else {
                                                                classes[0] = 1; 
                                                                classes[1] = 0; 
                                                            }
                                                        } else {
                                                            classes[0] = 3; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 16; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 79; 
                                            }
                                        } else {
                                            if (features[23] <= 0.5) {
                                                classes[0] = 0; 
                                                classes[1] = 104; 
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 123; 
                                    }
                                }
                            } else {
                                if (features[133] <= 0.5) {
                                    if (features[5] <= 0.5) {
                                        classes[0] = 10; 
                                        classes[1] = 247; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 2; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 15; 
                                }
                            }
                        } else {
                            if (features[114] <= 0.5) {
                                if (features[99] <= 0.5) {
                                    if (features[23] <= 0.5) {
                                        if (features[113] <= 0.5) {
                                            if (features[100] <= 0.5) {
                                                if (features[27] <= 0.5) {
                                                    if (features[133] <= 0.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 38; 
                                                    } else {
                                                        if (features[148] <= 0.5) {
                                                            if (features[139] <= 0.5) {
                                                                if (features[68] <= 0.5) {
                                                                    if (features[132] <= 0.5) {
                                                                        classes[0] = 2; 
                                                                        classes[1] = 1; 
                                                                    } else {
                                                                        classes[0] = 1; 
                                                                        classes[1] = 0; 
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
                                                            classes[0] = 0; 
                                                            classes[1] = 33; 
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 90; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 166; 
                                            }
                                        } else {
                                            classes[0] = 1; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        classes[0] = 4; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 6; 
                                    classes[1] = 0; 
                                }
                            } else {
                                classes[0] = 26; 
                                classes[1] = 0; 
                            }
                        }
                    } else {
                        if (features[15] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 300; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[114] <= 0.5) {
                        if (features[82] <= 0.5) {
                            if (features[131] <= 0.5) {
                                if (features[134] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 607; 
                                } else {
                                    classes[0] = 5; 
                                    classes[1] = 0; 
                                }
                            } else {
                                if (features[27] <= 0.5) {
                                    classes[0] = 44; 
                                    classes[1] = 0; 
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 84; 
                                }
                            }
                        } else {
                            classes[0] = 43; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 180; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[133] <= 0.5) {
                    classes[0] = 4; 
                    classes[1] = 1487; 
                } else {
                    classes[0] = 3; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[114] <= 0.5) {
                if (features[80] <= 0.5) {
                    if (features[45] <= 0.5) {
                        if (features[2] <= 0.5) {
                            if (features[134] <= 0.5) {
                                if (features[35] <= 0.5) {
                                    if (features[77] <= 0.5) {
                                        if (features[0] <= 0.5) {
                                            if (features[133] <= 0.5) {
                                                if (features[48] <= 0.5) {
                                                    if (features[135] <= 0.5) {
                                                        if (features[30] <= 0.5) {
                                                            if (features[11] <= 0.5) {
                                                                if (features[143] <= 0.5) {
                                                                    if (features[118] <= 0.5) {
                                                                        if (features[5] <= 0.5) {
                                                                            if (features[34] <= 0.5) {
                                                                                if (features[129] <= 0.5) {
                                                                                    classes[0] = 1601; 
                                                                                    classes[1] = 3891; 
                                                                                } else {
                                                                                    classes[0] = 9; 
                                                                                    classes[1] = 1; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 24; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 45; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 7; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 46; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 48; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 114; 
                                                        }
                                                    } else {
                                                        classes[0] = 51; 
                                                        classes[1] = 0; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 220; 
                                                }
                                            } else {
                                                if (features[11] <= 0.5) {
                                                    if (features[132] <= 0.5) {
                                                        if (features[68] <= 0.5) {
                                                            if (features[74] <= 0.5) {
                                                                if (features[66] <= 0.5) {
                                                                    if (features[148] <= 0.5) {
                                                                        if (features[123] <= 0.5) {
                                                                            if (features[5] <= 0.5) {
                                                                                if (features[129] <= 0.5) {
                                                                                    classes[0] = 369; 
                                                                                    classes[1] = 325; 
                                                                                } else {
                                                                                    classes[0] = 8; 
                                                                                    classes[1] = 0; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 9; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 14; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 13; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 16; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 23; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 41; 
                                                        }
                                                    } else {
                                                        if (features[139] <= 0.5) {
                                                            if (features[51] <= 0.5) {
                                                                if (features[131] <= 0.5) {
                                                                    if (features[136] <= 0.5) {
                                                                        classes[0] = 133; 
                                                                        classes[1] = 1; 
                                                                    } else {
                                                                        classes[0] = 6; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 26; 
                                                                    classes[1] = 0; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 4; 
                                                            }
                                                        } else {
                                                            if (features[131] <= 0.5) {
                                                                classes[0] = 0; 
                                                                classes[1] = 17; 
                                                            } else {
                                                                if (features[51] <= 0.5) {
                                                                    if (features[123] <= 0.5) {
                                                                        classes[0] = 23; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 2; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 5; 
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (features[23] <= 0.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 207; 
                                                    } else {
                                                        classes[0] = 6; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 291; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 309; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 313; 
                                }
                            } else {
                                if (features[133] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 18; 
                                } else {
                                    if (features[136] <= 0.5) {
                                        if (features[132] <= 0.5) {
                                            classes[0] = 150; 
                                            classes[1] = 1; 
                                        } else {
                                            classes[0] = 10; 
                                            classes[1] = 0; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 3; 
                                    }
                                }
                            }
                        } else {
                            if (features[113] <= 0.5) {
                                if (features[51] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 524; 
                                } else {
                                    if (features[89] <= 0.5) {
                                        if (features[33] <= 0.5) {
                                            classes[0] = 0; 
                                            classes[1] = 12; 
                                        } else {
                                            if (features[124] <= 0.5) {
                                                classes[0] = 2; 
                                                classes[1] = 0; 
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 2; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 92; 
                                    }
                                }
                            } else {
                                if (features[77] <= 0.5) {
                                    if (features[136] <= 0.5) {
                                        classes[0] = 2; 
                                        classes[1] = 0; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 1; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 3; 
                                }
                            }
                        }
                    } else {
                        if (features[134] <= 0.5) {
                            classes[0] = 0; 
                            classes[1] = 989; 
                        } else {
                            classes[0] = 15; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[33] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 6; 
                    } else {
                        if (features[17] <= 0.5) {
                            classes[0] = 801; 
                            classes[1] = 0; 
                        } else {
                            classes[0] = 0; 
                            classes[1] = 1; 
                        }
                    }
                }
            } else {
                if (features[133] <= 0.5) {
                    if (features[129] <= 0.5) {
                        if (features[2] <= 0.5) {
                            classes[0] = 2531; 
                            classes[1] = 2; 
                        } else {
                            classes[0] = 1; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 44; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 951; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[68] <= 0.5) {
            if (features[77] <= 0.5) {
                classes[0] = 76147; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 2; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 4; 
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