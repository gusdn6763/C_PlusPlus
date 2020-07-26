#include "Util.h"

using namespace std; 
  
int getNumber(const char* str)
{
    int value;
    string checkint;

    cout << str;
    cin >> checkint;
    for (int i = 0; i < (int)checkint.length(); i++)
    {
        if (isdigit(checkint[i]) == false)
        {
            cout << "숫자만 입력해주세요";
            return getNumber(str);
        }
    }
    value = std::stoi(checkint);
    return value;
}

int		ft_strcpy(char *dest, char *src)
{
	int     i;
	int     j;
	char	*src_tmp;

	i = strlen(src);
	j = -1;

	src_tmp = (char *)src;
	while (src_tmp[++j] != '\0')
		dest[j] = src_tmp[j];
	dest[j] = '\0';
	return (i);
}