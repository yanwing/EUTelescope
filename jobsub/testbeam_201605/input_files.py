#!/bin/python

# path for output files
output_path = "./plots/"

# path for input files
input_path = "./pos1/"

# thresholds
thresholds = [30,45,60,75,85,95,105,115,125,150,165,180]

# input files
files = ["TestbeamAnalysis_2767_pos1_30_500.root",
"TestbeamAnalysis_2768_pos1_45_500.root",
"TestbeamAnalysis_2769_2770_pos1_60_500.root",
"TestbeamAnalysis_2771_2772_2774_pos1_75_500.root",
"TestbeamAnalysis_2776_2777_pos1_85_500.root",
"TestbeamAnalysis_2778_2779_2860_pos1_95_500.root",
"TestbeamAnalysis_2780_2862_pos1_105_500.root",
"TestbeamAnalysis_2781_2863_2864_2865_pos1_115_500.root",
"TestbeamAnalysis_2782_pos1_125_500.root",
"TestbeamAnalysis_2788_2866_pos1_150_500.root",
"TestbeamAnalysis_2867_2868_pos1_165_500.root",
"TestbeamAnalysis_2869_2871_pos1_180_500.root"]

#thresholds = [30,45,60,75,85,95,105,115,125,150,165,180]

#files = ["TestbeamAnalysis_2767_pos1_30_500.root",
#"TestbeamAnalysis_2768_pos1_45_500.root",
#"TestbeamAnalysis_2769_2770_pos1_60_500.root",
#"TestbeamAnalysis_2771_2772_2774_pos1_75_500.root",
#"TestbeamAnalysis_2776_2777_pos1_85_500.root",
#"TestbeamAnalysis_2778_2779_2860_pos1_95_500.root",
#"TestbeamAnalysis_2780_2862_pos1_105_500.root",
#"TestbeamAnalysis_2781_2863_2864_2865_pos1_115_500.root",
#"TestbeamAnalysis_2782_pos1_125_500.root",
#"TestbeamAnalysis_2788_2866_pos1_150_500.root",
#"TestbeamAnalysis_2867_2868_pos1_165_500.root",
#"TestbeamAnalysis_2869_2871_pos1_180_500.root"]

#thresholds = [30,45,60,75,85,95,105,115,125,150,165,180]

#files = ["TestbeamAnalysis_2805_pos2_30_500.root",
#"TestbeamAnalysis_2807_pos2_45_500.root",
#"TestbeamAnalysis_2808_pos2_60_500.root",
#"TestbeamAnalysis_2809_pos2_75_500.root",
#"TestbeamAnalysis_2810_pos2_85_500.root",
#"TestbeamAnalysis_2811_2813_pos2_95_500.root",
#"TestbeamAnalysis_2820_pos2_105_500.root",
#"TestbeamAnalysis_2822_2824_2825_pos2_115_500.root",
#"TestbeamAnalysis_2826_2827_2832_pos2_125_500.root",
#"TestbeamAnalysis_2834_2835_pos2_150_500.root",
#"TestbeamAnalysis_2838_2839_pos2_165_500.root",
#"TestbeamAnalysis_2840_2841_2842_2843_pos2_180_500.root"]

#thresholds = [30,38,45,52,60,68,75,85,95,105,115,125,150,165,180]

#files = ["TestbeamAnalysis_2933_2934_pos1_30_600.root",
#"TestbeamAnalysis_2935_2936_2937_pos1_38_600.root",
#"TestbeamAnalysis_2938_2939_pos1_45_600.root",
#"TestbeamAnalysis_2940_2941_pos1_52_600.root",
#"TestbeamAnalysis_2929_2930_2931_2932_pos1_60_600.root",
#"TestbeamAnalysis_002942_pos1_68_600.root",
#"TestbeamAnalysis_2943_2944_2945_pos1_75_600.root",
#"TestbeamAnalysis_002946_pos1_85_600.root",
#"TestbeamAnalysis_2947_2948_pos1_95_600.root",
#"TestbeamAnalysis_002949_pos1_105_600.root",
#"TestbeamAnalysis_002951_pos1_115_600.root",
#"TestbeamAnalysis_2953_2954_pos1_125_600.root",
#"TestbeamAnalysis_2955_2956_2961_pos1_150_600.root",
#"TestbeamAnalysis_2962_2963_2965_2966_pos1_165_600.root",
#"TestbeamAnalysis_2967_2968_2969_2970_2971_pos1_180_600.root"]

#thresholds = [30,38,45,52,60,68,75,85,95,105,115,125,150,165,180]

#files = ["TestbeamAnalysis_2872_2874_pos2_30_600.root",
#"TestbeamAnalysis_2890_2891_pos2_38_600.root",
#"TestbeamAnalysis_2875_2876_2877_2881_2882_pos2_45_600.root",
#"TestbeamAnalysis_2892_pos2_52_600.root",
#"TestbeamAnalysis_2883_2884_2885_pos2_60_600.root",
#"TestbeamAnalysis_2893_2894_2895_2896_pos2_68_600.root",
#"TestbeamAnalysis_2899_pos2_75_600.root",
#"TestbeamAnalysis_2904_2905_2906_2907_pos2_85_600.root",
#"TestbeamAnalysis_2901_pos2_95_600.root",
#"TestbeamAnalysis_2902_2903_pos2_105_600.root",
#"TestbeamAnalysis_2908_2909_pos2_115_600.root",
#"TestbeamAnalysis_2910_2911_2914_pos2_125_600.root",
#"TestbeamAnalysis_2916_2920_pos2_150_600.root",
#"TestbeamAnalysis_2922_pos2_165_600.root",
#"TestbeamAnalysis_2923_pos2_180_600.root"]

#thresholds = [45,60,75,90,105,120,135,150,175]

#files = ["TestbeamAnalysis_000918_LS4_ASIC16_45_400.root",
#"TestbeamAnalysis_000894_LS4_ASIC16_60_400.root",
#"TestbeamAnalysis_000895_000896_LS4_ASIC16_75_400.root",
#"TestbeamAnalysis_000897_LS4_ASIC16_90_400.root",
#"TestbeamAnalysis_000902_LS4_ASIC16_105_400.root",
#"TestbeamAnalysis_000908_LS4_ASIC16_120_400.root",
#"TestbeamAnalysis_000910_000911_LS4_ASIC16_135_400.root",
#"TestbeamAnalysis_000912_000913_000915_LS4_ASIC16_150_400.root",
#"TestbeamAnalysis_000916_000917_LS4_ASIC16_175_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_001073_LS4_edgeASIC16_30_400.root",
#"TestbeamAnalysis_001074_LS4_edgeASIC16_45_400.root",
#"TestbeamAnalysis_001072_001075_LS4_edgeASIC16_60_400.root",
#"TestbeamAnalysis_001077_LS4_edgeASIC16_70_400.root",
#"TestbeamAnalysis_001079_LS4_edgeASIC16_80_400.root",
#"TestbeamAnalysis_001081_LS4_edgeASIC16_90_400.root",
#"TestbeamAnalysis_001082_LS4_edgeASIC16_105_400.root",
#"TestbeamAnalysis_001083_LS4_edgeASIC16_120_400.root",
#"TestbeamAnalysis_001084_LS4_edgeASIC16_135_400.root",
#"TestbeamAnalysis_001085_LS4_edgeASIC16_150_400.root",
#"TestbeamAnalysis_001086_LS4_edgeASIC16_165_400.root",
#"TestbeamAnalysis_001087_LS4_edgeASIC16_180_400.root"]

#thresholds = [30,45,60,75,85,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_000922_LS4_ASIC17_30_400.root",
#"TestbeamAnalysis_000923_LS4_ASIC17_45_400.root",
#"TestbeamAnalysis_000919_LS4_ASIC17_60_400.root",
#"TestbeamAnalysis_000924_LS4_ASIC17_75_400.root",
#"TestbeamAnalysis_000925_LS4_ASIC17_85_400.root",
#"TestbeamAnalysis_000921_LS4_ASIC17_90_400.root",
#"TestbeamAnalysis_000932_000933_000934_LS4_ASIC17_105_400.root",
#"TestbeamAnalysis_000935_LS4_ASIC17_120_400.root",
#"TestbeamAnalysis_000926_LS4_ASIC17_135_400.root",
#"TestbeamAnalysis_000927_LS4_ASIC17_150_400.root",
#"TestbeamAnalysis_000928_LS4_ASIC17_165_400.root",
#"TestbeamAnalysis_000930_000931_LS4_ASIC17_180_400.root"]

#thresholds = [30,45,60,70,80,90,105,115,120,135,150,165]

#files = ["TestbeamAnalysis_937_LS4_ASIC18_30_400.root",
#"TestbeamAnalysis_938_LS4_ASIC18_45_400.root",
#"TestbeamAnalysis_936_LS4_ASIC18_60_400.root",
#"TestbeamAnalysis_939_LS4_ASIC18_70_400.root",
#"TestbeamAnalysis_940_LS4_ASIC18_80_400.root",
#"TestbeamAnalysis_942_LS4_ASIC18_90_400.root",
#"TestbeamAnalysis_943_LS4_ASIC18_105_400.root",
#"TestbeamAnalysis_944_945_LS4_ASIC18_115_400.root",
#"TestbeamAnalysis_946_LS4_ASIC18_120_400.root",
#"TestbeamAnalysis_947_LS4_ASIC18_135_400.root",
#"TestbeamAnalysis_948_LS4_ASIC18_150_400.root",
#"TestbeamAnalysis_949_LS4_ASIC18_165_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_953_LS4_ASIC19_30_400.root",
#"TestbeamAnalysis_954_LS4_ASIC19_45_400.root",
#"TestbeamAnalysis_952_LS4_ASIC19_60_400.root",
#"TestbeamAnalysis_956_LS4_ASIC19_70_400.root",
#"TestbeamAnalysis_957_LS4_ASIC19_80_400.root",
#"TestbeamAnalysis_958_LS4_ASIC19_90_400.root",
#"TestbeamAnalysis_959_LS4_ASIC19_105_400.root",
#"TestbeamAnalysis_960_LS4_ASIC19_120_400.root",
#"TestbeamAnalysis_961_962_LS4_ASIC19_135_400.root",
#"TestbeamAnalysis_963_LS4_ASIC19_150_400.root",
#"TestbeamAnalysis_964_LS4_ASIC19_165_400.root",
#"TestbeamAnalysis_965_LS4_ASIC19_180_400.root"]

#thresholds = [60,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_970_LS4_ASIC20_60_400.root",
#"TestbeamAnalysis_973_LS4_ASIC20_90_400.root",
#"TestbeamAnalysis_976_LS4_ASIC20_105_400.root",
#"TestbeamAnalysis_977_LS4_ASIC20_120_400.root",
#"TestbeamAnalysis_978_LS4_ASIC20_135_400.root",
#"TestbeamAnalysis_979_LS4_ASIC20_150_400.root",
#"TestbeamAnalysis_980_LS4_ASIC20_165_400.root",
#"TestbeamAnalysis_968_981_LS4_ASIC20_180_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_982_LS4_ASIC21_30_400.root",
#"TestbeamAnalysis_983_LS4_ASIC21_45_400.root",
#"TestbeamAnalysis_984_LS4_ASIC21_60_400.root",
#"TestbeamAnalysis_985_LS4_ASIC21_70_400.root",
#"TestbeamAnalysis_986_LS4_ASIC21_80_400.root",
#"TestbeamAnalysis_987_LS4_ASIC21_90_400.root",
#"TestbeamAnalysis_988_LS4_ASIC21_105_400.root",
#"TestbeamAnalysis_989_LS4_ASIC21_120_400.root",
#"TestbeamAnalysis_990_LS4_ASIC21_135_400.root",
#"TestbeamAnalysis_991_LS4_ASIC21_150_400.root",
#"TestbeamAnalysis_992_LS4_ASIC21_165_400.root",
#"TestbeamAnalysis_993_LS4_ASIC21_180_400.root"]

# thresholds =[DAQLOAD14threhsolds]
#
# files = ["DL13testbeamanalysis files.root",
# "TestbeamAnalysis_983_LS4_ASIC21_45_400.root",
# "TestbeamAnalysis_984_LS4_ASIC21_60_400.root",
# "TestbeamAnalysis_985_LS4_ASIC21_70_400.root",
# "TestbeamAnalysis_986_LS4_ASIC21_80_400.root",
# "TestbeamAnalysis_987_LS4_ASIC21_90_400.root",
# "TestbeamAnalysis_988_LS4_ASIC21_105_400.root",
# "TestbeamAnalysis_989_LS4_ASIC21_120_400.root",
# "TestbeamAnalysis_990_LS4_ASIC21_135_400.root",
# "TestbeamAnalysis_991_LS4_ASIC21_150_400.root",
# "TestbeamAnalysis_992_LS4_ASIC21_165_400.root",
# "TestbeamAnalysis_993_LS4_ASIC21_180_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_000994_LS4_ASIC22_30_400.root",
#"TestbeamAnalysis_000995_LS4_ASIC22_45_400.root",
#"TestbeamAnalysis_000996_LS4_ASIC22_60_400.root",
#"TestbeamAnalysis_000997_LS4_ASIC22_70_400.root",
#"TestbeamAnalysis_000998_LS4_ASIC22_80_400.root",
#"TestbeamAnalysis_000999_LS4_ASIC22_90_400.root",
#"TestbeamAnalysis_001000_LS4_ASIC22_105_400.root",
#"TestbeamAnalysis_001001_LS4_ASIC22_120_400.root",
#"TestbeamAnalysis_001002_LS4_ASIC22_135_400.root",
#"TestbeamAnalysis_001003_LS4_ASIC22_150_400.root",
#"TestbeamAnalysis_001004_LS4_ASIC22_165_400.root",
#"TestbeamAnalysis_001005_LS4_ASIC22_180_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_001006_LS4_ASIC23_30_400.root",
#"TestbeamAnalysis_001007_LS4_ASIC23_45_400.root",
#"TestbeamAnalysis_001008_LS4_ASIC23_60_400.root",
#"TestbeamAnalysis_001009_LS4_ASIC23_70_400.root",
#"TestbeamAnalysis_001010_LS4_ASIC23_80_400.root",
#"TestbeamAnalysis_001011_LS4_ASIC23_90_400.root",
#"TestbeamAnalysis_001012_LS4_ASIC23_105_400.root",
#"TestbeamAnalysis_001013_LS4_ASIC23_120_400.root",
#"TestbeamAnalysis_001014_LS4_ASIC23_135_400.root",
#"TestbeamAnalysis_001015_LS4_ASIC23_150_400.root",
#"TestbeamAnalysis_001016_LS4_ASIC23_165_400.root",
#"TestbeamAnalysis_001017_LS4_ASIC23_180_400.root"]

#thresholds = [30,45,60,70,80,90,105,120,135,150,165,180]

#files = ["TestbeamAnalysis_001018_LS4_ASIC24_30_400.root",
#"TestbeamAnalysis_001019_LS4_ASIC24_45_400.root",
#"TestbeamAnalysis_001020_LS4_ASIC24_60_400.root",
#"TestbeamAnalysis_001021_LS4_ASIC24_70_400.root",
#"TestbeamAnalysis_001022_LS4_ASIC24_80_400.root",
#"TestbeamAnalysis_001023_LS4_ASIC24_90_400.root",
#"TestbeamAnalysis_001024_LS4_ASIC24_105_400.root",
#"TestbeamAnalysis_001025_LS4_ASIC24_120_400.root",
#"TestbeamAnalysis_001026_LS4_ASIC24_135_400.root",
#"TestbeamAnalysis_001027_LS4_ASIC24_150_400.root",
#"TestbeamAnalysis_001028_LS4_ASIC24_165_400.root",
#"TestbeamAnalysis_001029_LS4_ASIC24_180_400.root"]
