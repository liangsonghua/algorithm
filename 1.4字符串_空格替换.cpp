class Replacement {
public:
	string replaceSpace(string iniString, int length) {
      string result = "";
	  for(int i=0;i<length;i++)
	  {
	    if(iniString[i] ==' ')
		{
		  result+="%20";
		}
		else
			result+=iniString[i];
	  }
      return result;
	}
    
};
