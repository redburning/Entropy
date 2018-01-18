#include "Entropy.h"

//Implementation of entropy
CEntropy::CEntropy(vector<vector<int>> X)
{
	this->entropy = 0.0;
	this->X = X;
}

CEntropy::CEntropy(vector<int> X)
{
	this->entropy = 0.0;
	this->X.push_back(X);
}

CEntropy::~CEntropy()
{
	for (int i = 0; i < (int)X.size(); i++){
		X[i].swap(vector<int>());
	}
	X.swap(vector<vector<int>>());

	uniqueData.swap(vector<string>());
	frequency.swap(vector<double>());
}


void CEntropy::calculateEntropy(){
	int max = getMax();
	int cardinal = max + 1;
	for (int i = 0; i < (int)X[0].size(); i++){
		string str;
		for (int j = 0; j < (int)X.size(); j++){
			char tempStr[10000];
			_itoa_s(X[j][i], tempStr, cardinal);
			string s(tempStr);
			str += s;
		}
		int index = getKey(str);
		if (index != -1){
			frequency[index]++;
		}
		else{
			uniqueData.push_back(str);
			frequency.push_back(1);
		}
	}

	for (int i = 0; i < (int)frequency.size(); i++){
		double probability = frequency[i] / X[0].size();
		entropy -= probability * logBaseTwo(probability);
	}
}

int CEntropy::getKey(string s){
	for (int i = 0; i < (int)uniqueData.size(); i++){
		if (uniqueData[i] == s)
			return i;
	}
	return -1;
}

int CEntropy::getMax(){
	int max = X[0][0];
	for (int i = 0; i < (int)X.size(); i++){
		for (int j = 0; j < (int)X[i].size(); j++){
			if (X[i][j] > max)
				max = X[i][j];
		}
	}
	return max;
}

double CEntropy::getEntropy(){
	if (!X.empty())
		calculateEntropy();
	return this->entropy;
}

double CEntropy::logBaseTwo(double x){
	return log(x) / log(2);
}





//Implementation of conditional entropy
CConditionalEntropy::CConditionalEntropy(vector<vector<int>> X, vector<vector<int>> X_condition)
{
	this->X = X;
	this->X_condition = X_condition;
	this->conditionalEntropy = 0.0;
}

CConditionalEntropy::CConditionalEntropy(vector<vector<int>> X, vector<int> X_condition)
{
	this->X = X;
	this->X_condition.push_back(X_condition);
	this->conditionalEntropy = 0.0;
}

CConditionalEntropy::CConditionalEntropy(vector<int> X, vector<vector<int>> X_condition)
{
	this->X.push_back(X);
	this->X_condition = X_condition;
	this->conditionalEntropy = 0.0;
}

CConditionalEntropy::CConditionalEntropy(vector<int> X, vector<int> X_condition)
{
	this->X.push_back(X);
	this->X_condition.push_back(X_condition);
	this->conditionalEntropy = 0.0;
}

void CConditionalEntropy::calculateConditionalEntropy(){
	vector<vector<int>> T = X;
	for (int i = 0; i < (int)X_condition.size(); i++)
		T.push_back(X_condition[i]);
	CEntropy allVars(T);
	CEntropy conditionalVars(X_condition);
	conditionalEntropy = allVars.getEntropy() - conditionalVars.getEntropy();
}

double CConditionalEntropy::getConditionalEntropy(){
	if (!X.empty() && !X_condition.empty())
		calculateConditionalEntropy();
	return this->conditionalEntropy;
}

CConditionalEntropy::~CConditionalEntropy()
{
	for (int i = 0; i < (int)X.size(); i++){
		X[i].swap(vector<int>());
	}
	X.swap(vector<vector<int>>());

	for (int i = 0; i < (int)X_condition.size(); i++){
		X_condition[i].swap(vector<int>());
	}
	X_condition.swap(vector<vector<int>>());
}






//Implementation of mutual information
CMutualInformation::CMutualInformation(vector<vector<int>> X, vector<int> Y)
{
	this->X = X;
	this->Y = Y;
	this->mutualInformation = 0.0;
	this->symmetricUncertainty = 0.0;
}


CMutualInformation::CMutualInformation(vector<int> X, vector<int> Y)
{
	this->X.push_back(X);
	this->Y = Y;
	this->mutualInformation = 0.0;
	this->symmetricUncertainty = 0.0;
}


CMutualInformation::~CMutualInformation()
{
	for (int i = 0; i < (int)X.size(); i++){
		X[i].swap(vector<int>());
	}
	X.swap(vector<vector<int>>());

	Y.swap(vector<int>());
}


void CMutualInformation::calculateMutualInformation(){
	vector<vector<int>> XY = X;
	XY.push_back(Y);
	CEntropy x(X);
	CEntropy y(Y);
	CEntropy xy(XY);
	mutualInformation = x.getEntropy() + y.getEntropy() - xy.getEntropy();
}

double CMutualInformation::getMutualInformation(){
	if (!X.empty() && !Y.empty())
		calculateMutualInformation();
	return this->mutualInformation;
}






//Implementation of conditional mutual information
CConditionalMutualInformation::CConditionalMutualInformation(vector<int> X, vector<int> Y, vector<int> X_condition){
	this->X.push_back(X);
	this->Y = Y;
	this->X_dondition.push_back(X_condition);
	this->conditionalMutualInformation = 0.0;
}

CConditionalMutualInformation::CConditionalMutualInformation(vector<vector<int>> X, vector<int> Y, vector<int> X_condition){
	this->X = X;
	this->Y = Y;
	this->X_dondition.push_back(X_condition);
	this->conditionalMutualInformation = 0.0;
}

CConditionalMutualInformation::CConditionalMutualInformation(vector<vector<int>> X, vector<int> Y, vector<vector<int>> X_condition){
	this->X = X;
	this->Y = Y;
	this->X_dondition = X_condition;
	this->conditionalMutualInformation = 0.0;
}

CConditionalMutualInformation::~CConditionalMutualInformation(){
	for (int i = 0; i < (int)X.size(); i++){
		X[i].swap(vector<int>());
	}
	X.swap(vector<vector<int>>());
	Y.swap(vector<int>());
	for (int i = 0; i < (int)X_dondition.size(); i++){
		X_dondition[i].swap(vector<int>());
	}
	X_dondition.swap(vector<vector<int>>());
}

//I(X; Y | X_condition) = H(X | X_condition) + H(Y | X_condition) - H(X, Y | X_condition)
void CConditionalMutualInformation::calculateConditionalMutualInformation(){
	CConditionalEntropy x_x_condition(X, X_dondition);
	CConditionalEntropy y_x_condition(Y, X_dondition);
	vector<vector<int>> xy = X;
	xy.push_back(Y);
	CConditionalEntropy xy_x_condition(xy, X_dondition);
	this->conditionalMutualInformation = x_x_condition.getConditionalEntropy() 
		+ y_x_condition.getConditionalEntropy() 
		- xy_x_condition.getConditionalEntropy();
}

double CConditionalMutualInformation::getConditionalMutualInformation(){
	if (!X.empty() && !Y.empty() && !X_dondition.empty())
		calculateConditionalMutualInformation();
	return this->conditionalMutualInformation;
}