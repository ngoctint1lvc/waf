#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int predict(float features[159]) {

    int classes[2];
        
    if (features[128] <= 0.5) {
        if (features[154] <= 0.5) {
            if (features[114] <= 0.5) {
                if (features[45] <= 0.5) {
                    if (features[156] <= 0.5) {
                        if (features[80] <= 0.5) {
                            if (features[139] <= 0.5) {
                                if (features[77] <= 0.5) {
                                    if (features[0] <= 0.5) {
                                        if (features[11] <= 0.5) {
                                            if (features[75] <= 0.5) {
                                                if (features[48] <= 0.5) {
                                                    if (features[153] <= 0.5) {
                                                        if (features[143] <= 0.5) {
                                                            if (features[132] <= 0.5) {
                                                                if (features[5] <= 0.5) {
                                                                    if (features[68] <= 0.5) {
                                                                        if (features[135] <= 0.5) {
                                                                            if (features[34] <= 0.5) {
                                                                                if (features[74] <= 0.5) {
                                                                                    if (features[21] <= 0.5) {
                                                                                        if (features[157] <= 0.5) {
                                                                                            classes[0] = 19; 
                                                                                            classes[1] = 0; 
                                                                                        } else {
                                                                                            if (features[66] <= 0.5) {
                                                                                                if (features[134] <= 0.5) {
                                                                                                    if (features[129] <= 0.5) {
                                                                                                        if (features[123] <= 0.5) {
                                                                                                            if (features[148] <= 0.5) {
                                                                                                                if (features[33] <= 0.5) {
                                                                                                                    if (features[120] <= 0.5) {
                                                                                                                        if (features[145] <= 0.5) {
                                                                                                                            classes[0] = 6886; 
                                                                                                                            classes[1] = 23632; 
                                                                                                                        } else {
                                                                                                                            classes[0] = 0; 
                                                                                                                            classes[1] = 17; 
                                                                                                                        }
                                                                                                                    } else {
                                                                                                                        classes[0] = 0; 
                                                                                                                        classes[1] = 11; 
                                                                                                                    }
                                                                                                                } else {
                                                                                                                    classes[0] = 0; 
                                                                                                                    classes[1] = 17; 
                                                                                                                }
                                                                                                            } else {
                                                                                                                classes[0] = 0; 
                                                                                                                classes[1] = 51; 
                                                                                                            }
                                                                                                        } else {
                                                                                                            classes[0] = 7; 
                                                                                                            classes[1] = 0; 
                                                                                                        }
                                                                                                    } else {
                                                                                                        classes[0] = 10; 
                                                                                                        classes[1] = 0; 
                                                                                                    }
                                                                                                } else {
                                                                                                    if (features[133] <= 0.5) {
                                                                                                        classes[0] = 0; 
                                                                                                        classes[1] = 91; 
                                                                                                    } else {
                                                                                                        if (features[2] <= 0.5) {
                                                                                                            classes[0] = 83; 
                                                                                                            classes[1] = 5; 
                                                                                                        } else {
                                                                                                            classes[0] = 0; 
                                                                                                            classes[1] = 5; 
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            } else {
                                                                                                classes[0] = 0; 
                                                                                                classes[1] = 97; 
                                                                                            }
                                                                                        }
                                                                                    } else {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 132; 
                                                                                    }
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 143; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 143; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 31; 
                                                                            classes[1] = 0; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 218; 
                                                                    }
                                                                } else {
                                                                    if (features[118] <= 0.5) {
                                                                        if (features[133] <= 0.5) {
                                                                            classes[0] = 5; 
                                                                            classes[1] = 292; 
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 80; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 3; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                }
                                                            } else {
                                                                if (features[68] <= 0.5) {
                                                                    classes[0] = 99; 
                                                                    classes[1] = 0; 
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 17; 
                                                                }
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 614; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 654; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 1343; 
                                                }
                                            } else {
                                                if (features[133] <= 0.5) {
                                                    if (features[5] <= 0.5) {
                                                        classes[0] = 4; 
                                                        classes[1] = 1526; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 11; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 80; 
                                                }
                                            }
                                        } else {
                                            if (features[23] <= 0.5) {
                                                if (features[113] <= 0.5) {
                                                    classes[0] = 0; 
                                                    classes[1] = 1739; 
                                                } else {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                classes[0] = 1; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 1745; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 1951; 
                                }
                            } else {
                                if (features[136] <= 0.5) {
                                    if (features[79] <= 0.5) {
                                        if (features[9] <= 0.5) {
                                            if (features[23] <= 0.5) {
                                                if (features[118] <= 0.5) {
                                                    if (features[132] <= 0.5) {
                                                        if (features[77] <= 0.5) {
                                                            if (features[133] <= 0.5) {
                                                                classes[0] = 7; 
                                                                classes[1] = 160; 
                                                            } else {
                                                                if (features[112] <= 0.5) {
                                                                    if (features[60] <= 0.5) {
                                                                        classes[0] = 2; 
                                                                        classes[1] = 5; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 5; 
                                                                }
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 51; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 166; 
                                                    }
                                                } else {
                                                    if (features[100] <= 0.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 11; 
                                                    } else {
                                                        classes[0] = 5; 
                                                        classes[1] = 0; 
                                                    }
                                                }
                                            } else {
                                                classes[0] = 3; 
                                                classes[1] = 0; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 958; 
                                        }
                                    } else {
                                        classes[0] = 8; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    if (features[95] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 3386; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 0; 
                                    }
                                }
                            }
                        } else {
                            if (features[77] <= 0.5) {
                                if (features[131] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 5; 
                                } else {
                                    classes[0] = 452; 
                                    classes[1] = 0; 
                                }
                            } else {
                                classes[0] = 0; 
                                classes[1] = 22; 
                            }
                        }
                    } else {
                        classes[0] = 412; 
                        classes[1] = 0; 
                    }
                } else {
                    if (features[134] <= 0.5) {
                        classes[0] = 0; 
                        classes[1] = 5573; 
                    } else {
                        classes[0] = 9; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[133] <= 0.5) {
                    if (features[129] <= 0.5) {
                        if (features[156] <= 0.5) {
                            if (features[2] <= 0.5) {
                                classes[0] = 1392; 
                                classes[1] = 5; 
                            } else {
                                classes[0] = 0; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 0; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 23; 
                        classes[1] = 0; 
                    }
                } else {
                    classes[0] = 521; 
                    classes[1] = 0; 
                }
            }
        } else {
            if (features[138] <= 0.5) {
                if (features[45] <= 0.5) {
                    if (features[139] <= 0.5) {
                        if (features[11] <= 0.5) {
                            if (features[68] <= 0.5) {
                                if (features[149] <= 0.5) {
                                    if (features[133] <= 0.5) {
                                        if (features[5] <= 0.5) {
                                            if (features[143] <= 0.5) {
                                                if (features[134] <= 0.5) {
                                                    if (features[77] <= 0.5) {
                                                        if (features[100] <= 0.5) {
                                                            if (features[62] <= 0.5) {
                                                                if (features[23] <= 0.5) {
                                                                    if (features[129] <= 0.5) {
                                                                        if (features[12] <= 0.5) {
                                                                            if (features[33] <= 0.5) {
                                                                                if (features[106] <= 0.5) {
                                                                                    if (features[51] <= 0.5) {
                                                                                        if (features[60] <= 0.5) {
                                                                                            if (features[114] <= 0.5) {
                                                                                                if (features[1] <= 0.5) {
                                                                                                    if (features[145] <= 0.5) {
                                                                                                        if (features[136] <= 0.5) {
                                                                                                            if (features[99] <= 0.5) {
                                                                                                                if (features[98] <= 0.5) {
                                                                                                                    if (features[8] <= 0.5) {
                                                                                                                        if (features[125] <= 0.5) {
                                                                                                                            classes[0] = 34467; 
                                                                                                                            classes[1] = 25704; 
                                                                                                                        } else {
                                                                                                                            classes[0] = 1; 
                                                                                                                            classes[1] = 0; 
                                                                                                                        }
                                                                                                                    } else {
                                                                                                                        classes[0] = 1; 
                                                                                                                        classes[1] = 0; 
                                                                                                                    }
                                                                                                                } else {
                                                                                                                    classes[0] = 2; 
                                                                                                                    classes[1] = 0; 
                                                                                                                }
                                                                                                            } else {
                                                                                                                classes[0] = 2; 
                                                                                                                classes[1] = 0; 
                                                                                                            }
                                                                                                        } else {
                                                                                                            classes[0] = 0; 
                                                                                                            classes[1] = 5; 
                                                                                                        }
                                                                                                    } else {
                                                                                                        classes[0] = 0; 
                                                                                                        classes[1] = 5; 
                                                                                                    }
                                                                                                } else {
                                                                                                    classes[0] = 9; 
                                                                                                    classes[1] = 0; 
                                                                                                }
                                                                                            } else {
                                                                                                if (features[102] <= 0.5) {
                                                                                                    if (features[94] <= 0.5) {
                                                                                                        classes[0] = 48; 
                                                                                                        classes[1] = 0; 
                                                                                                    } else {
                                                                                                        classes[0] = 0; 
                                                                                                        classes[1] = 5; 
                                                                                                    }
                                                                                                } else {
                                                                                                    classes[0] = 0; 
                                                                                                    classes[1] = 5; 
                                                                                                }
                                                                                            }
                                                                                        } else {
                                                                                            classes[0] = 15; 
                                                                                            classes[1] = 0; 
                                                                                        }
                                                                                    } else {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 11; 
                                                                                    }
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 11; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 11; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 17; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 36; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 55; 
                                                                    classes[1] = 0; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 45; 
                                                            }
                                                        } else {
                                                            classes[0] = 77; 
                                                            classes[1] = 0; 
                                                        }
                                                    } else {
                                                        if (features[129] <= 0.5) {
                                                            if (features[111] <= 0.5) {
                                                                if (features[7] <= 0.5) {
                                                                    if (features[10] <= 0.5) {
                                                                        if (features[123] <= 0.5) {
                                                                            if (features[38] <= 0.5) {
                                                                                if (features[141] <= 0.5) {
                                                                                    if (features[13] <= 0.5) {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 0; 
                                                                                    } else {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 5; 
                                                                                    }
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 5; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 0; 
                                                                                classes[1] = 5; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 11; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 11; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 11; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 17; 
                                                            }
                                                        } else {
                                                            classes[0] = 1; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 63; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 120; 
                                            }
                                        } else {
                                            if (features[123] <= 0.5) {
                                                if (features[91] <= 0.5) {
                                                    if (features[77] <= 0.5) {
                                                        classes[0] = 0; 
                                                        classes[1] = 206; 
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 11; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 97; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    } else {
                                        if (features[42] <= 0.5) {
                                            if (features[77] <= 0.5) {
                                                if (features[106] <= 0.5) {
                                                    if (features[148] <= 0.5) {
                                                        if (features[132] <= 0.5) {
                                                            if (features[66] <= 0.5) {
                                                                if (features[134] <= 0.5) {
                                                                    if (features[62] <= 0.5) {
                                                                        if (features[102] <= 0.5) {
                                                                            if (features[114] <= 0.5) {
                                                                                if (features[51] <= 0.5) {
                                                                                    if (features[33] <= 0.5) {
                                                                                        if (features[69] <= 0.5) {
                                                                                            if (features[80] <= 0.5) {
                                                                                                if (features[136] <= 0.5) {
                                                                                                    if (features[5] <= 0.5) {
                                                                                                        if (features[23] <= 0.5) {
                                                                                                            if (features[60] <= 0.5) {
                                                                                                                if (features[111] <= 0.5) {
                                                                                                                    classes[0] = 3649; 
                                                                                                                    classes[1] = 614; 
                                                                                                                } else {
                                                                                                                    classes[0] = 0; 
                                                                                                                    classes[1] = 0; 
                                                                                                                }
                                                                                                            } else {
                                                                                                                classes[0] = 3; 
                                                                                                                classes[1] = 0; 
                                                                                                            }
                                                                                                        } else {
                                                                                                            classes[0] = 6; 
                                                                                                            classes[1] = 0; 
                                                                                                        }
                                                                                                    } else {
                                                                                                        classes[0] = 9; 
                                                                                                        classes[1] = 5; 
                                                                                                    }
                                                                                                } else {
                                                                                                    if (features[123] <= 0.5) {
                                                                                                        classes[0] = 18; 
                                                                                                        classes[1] = 11; 
                                                                                                    } else {
                                                                                                        classes[0] = 0; 
                                                                                                        classes[1] = 0; 
                                                                                                    }
                                                                                                }
                                                                                            } else {
                                                                                                classes[0] = 0; 
                                                                                                classes[1] = 5; 
                                                                                            }
                                                                                        } else {
                                                                                            classes[0] = 0; 
                                                                                            classes[1] = 5; 
                                                                                        }
                                                                                    } else {
                                                                                        classes[0] = 0; 
                                                                                        classes[1] = 5; 
                                                                                    }
                                                                                } else {
                                                                                    classes[0] = 0; 
                                                                                    classes[1] = 11; 
                                                                                }
                                                                            } else {
                                                                                classes[0] = 246; 
                                                                                classes[1] = 0; 
                                                                            }
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 11; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 11; 
                                                                    }
                                                                } else {
                                                                    if (features[114] <= 0.5) {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 22; 
                                                                    } else {
                                                                        classes[0] = 12; 
                                                                        classes[1] = 0; 
                                                                    }
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 17; 
                                                            }
                                                        } else {
                                                            if (features[89] <= 0.5) {
                                                                classes[0] = 528; 
                                                                classes[1] = 0; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 11; 
                                                            }
                                                        }
                                                    } else {
                                                        if (features[131] <= 0.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 45; 
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 0; 
                                                        }
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 45; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 63; 
                                            }
                                        } else {
                                            if (features[114] <= 0.5) {
                                                if (features[134] <= 0.5) {
                                                    classes[0] = 0; 
                                                    classes[1] = 441; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                classes[0] = 8; 
                                                classes[1] = 0; 
                                            }
                                        }
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 637; 
                                }
                            } else {
                                if (features[133] <= 0.5) {
                                    if (features[72] <= 0.5) {
                                        if (features[96] <= 0.5) {
                                            if (features[27] <= 0.5) {
                                                if (features[114] <= 0.5) {
                                                    if (features[108] <= 0.5) {
                                                        if (features[35] <= 0.5) {
                                                            if (features[26] <= 0.5) {
                                                                if (features[83] <= 0.5) {
                                                                    if (features[42] <= 0.5) {
                                                                        classes[0] = 7; 
                                                                        classes[1] = 97; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 5; 
                                                                    }
                                                                } else {
                                                                    classes[0] = 0; 
                                                                    classes[1] = 5; 
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 22; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 28; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 40; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 68; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 80; 
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 80; 
                                        }
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 103; 
                                    }
                                } else {
                                    classes[0] = 0; 
                                    classes[1] = 304; 
                                }
                            }
                        } else {
                            if (features[114] <= 0.5) {
                                if (features[23] <= 0.5) {
                                    if (features[99] <= 0.5) {
                                        if (features[131] <= 0.5) {
                                            if (features[119] <= 0.5) {
                                                if (features[27] <= 0.5) {
                                                    if (features[148] <= 0.5) {
                                                        if (features[133] <= 0.5) {
                                                            classes[0] = 0; 
                                                            classes[1] = 126; 
                                                        } else {
                                                            if (features[8] <= 0.5) {
                                                                classes[0] = 2; 
                                                                classes[1] = 5; 
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 5; 
                                                            }
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 264; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 287; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 568; 
                                            }
                                        } else {
                                            if (features[8] <= 0.5) {
                                                if (features[86] <= 0.5) {
                                                    classes[0] = 1; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 11; 
                                                }
                                            } else {
                                                classes[0] = 0; 
                                                classes[1] = 11; 
                                            }
                                        }
                                    } else {
                                        classes[0] = 1; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    classes[0] = 2; 
                                    classes[1] = 0; 
                                }
                            } else {
                                classes[0] = 5; 
                                classes[1] = 0; 
                            }
                        }
                    } else {
                        if (features[114] <= 0.5) {
                            if (features[23] <= 0.5) {
                                if (features[80] <= 0.5) {
                                    if (features[16] <= 0.5) {
                                        if (features[136] <= 0.5) {
                                            if (features[145] <= 0.5) {
                                                if (features[113] <= 0.5) {
                                                    if (features[9] <= 0.5) {
                                                        if (features[106] <= 0.5) {
                                                            if (features[68] <= 0.5) {
                                                                if (features[131] <= 0.5) {
                                                                    if (features[133] <= 0.5) {
                                                                        if (features[123] <= 0.5) {
                                                                            classes[0] = 1; 
                                                                            classes[1] = 5; 
                                                                        } else {
                                                                            classes[0] = 0; 
                                                                            classes[1] = 22; 
                                                                        }
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 22; 
                                                                    }
                                                                } else {
                                                                    if (features[121] <= 0.5) {
                                                                        classes[0] = 2; 
                                                                        classes[1] = 0; 
                                                                    } else {
                                                                        classes[0] = 0; 
                                                                        classes[1] = 5; 
                                                                    }
                                                                }
                                                            } else {
                                                                classes[0] = 0; 
                                                                classes[1] = 57; 
                                                            }
                                                        } else {
                                                            classes[0] = 0; 
                                                            classes[1] = 401; 
                                                        }
                                                    } else {
                                                        classes[0] = 0; 
                                                        classes[1] = 568; 
                                                    }
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 0; 
                                                }
                                            } else {
                                                if (features[106] <= 0.5) {
                                                    classes[0] = 2; 
                                                    classes[1] = 0; 
                                                } else {
                                                    classes[0] = 0; 
                                                    classes[1] = 34; 
                                                }
                                            }
                                        } else {
                                            classes[0] = 0; 
                                            classes[1] = 2370; 
                                        }
                                    } else {
                                        classes[0] = 2; 
                                        classes[1] = 0; 
                                    }
                                } else {
                                    if (features[33] <= 0.5) {
                                        classes[0] = 0; 
                                        classes[1] = 91; 
                                    } else {
                                        classes[0] = 12; 
                                        classes[1] = 0; 
                                    }
                                }
                            } else {
                                classes[0] = 7; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 266; 
                            classes[1] = 0; 
                        }
                    }
                } else {
                    if (features[114] <= 0.5) {
                        if (features[89] <= 0.5) {
                            if (features[134] <= 0.5) {
                                if (features[131] <= 0.5) {
                                    classes[0] = 0; 
                                    classes[1] = 3518; 
                                } else {
                                    if (features[27] <= 0.5) {
                                        classes[0] = 17; 
                                        classes[1] = 0; 
                                    } else {
                                        classes[0] = 0; 
                                        classes[1] = 436; 
                                    }
                                }
                            } else {
                                classes[0] = 8; 
                                classes[1] = 0; 
                            }
                        } else {
                            classes[0] = 20; 
                            classes[1] = 0; 
                        }
                    } else {
                        classes[0] = 105; 
                        classes[1] = 0; 
                    }
                }
            } else {
                if (features[133] <= 0.5) {
                    classes[0] = 0; 
                    classes[1] = 8346; 
                } else {
                    classes[0] = 0; 
                    classes[1] = 0; 
                }
            }
        }
    } else {
        if (features[68] <= 0.5) {
            if (features[77] <= 0.5) {
                classes[0] = 41719; 
                classes[1] = 0; 
            } else {
                classes[0] = 0; 
                classes[1] = 11; 
            }
        } else {
            classes[0] = 0; 
            classes[1] = 40; 
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