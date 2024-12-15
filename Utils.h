#define SET_BIT(REG,BIT) (REG=REG|(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define TGL_BIT(REG,BIT)  (REG=REG^(1<<BIT))
