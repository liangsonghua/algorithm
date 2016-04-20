class Reverse {
public:
    string reverseString(string iniString) {
        int len = iniString.size();
        int i = 0;
        int temp;
        for(;i<len/2;i++){
            temp = iniString[len-i-1];
            iniString[len-i-1] = iniString[i];
            iniString[i] = temp;
        }
        return iniString;
    }
};