#include<sstream>
int convertirInt(std::string s) {
	std::stringstream r(s);
	int v;		
	r >> v;		
	return v;
}
double convertirDouble(std::string s) {
	std::stringstream r(s);
	double v;		
	r >> v;		
	return v;
}