#pragma once

#include <vector>
#include <math.h>
using namespace std;



//Entropy
class CEntropy
{
private:
	vector<vector<int>> X;
	vector<string> uniqueData;
	vector<double> frequency;
	double entropy;

	void calculateEntropy();
	double logBaseTwo(double x);
	int getKey(string s);
	int getMax();

public:
	CEntropy(vector<vector<int>> X);
	CEntropy(vector<int> X);
	double getEntropy();

	~CEntropy();
};



//Conditional entropy
class CConditionalEntropy
{
private:
	vector<vector<int>> X;
	vector<vector<int>> X_condition;
	double conditionalEntropy;

	void calculateConditionalEntropy();

public:
	CConditionalEntropy(vector<vector<int>> X, vector<vector<int>> X_condition);
	CConditionalEntropy(vector<vector<int>> X, vector<int> X_condition);
	CConditionalEntropy(vector<int> X, vector<vector<int>> X_condition);
	CConditionalEntropy(vector<int> X, vector<int> X_condition);
	double getConditionalEntropy();

	~CConditionalEntropy();
};



//Mutual information
class CMutualInformation
{
private:
	vector<vector<int>> X;
	vector<int> Y;
	double mutualInformation;
	double symmetricUncertainty;
	void calculateMutualInformation();

public:
	CMutualInformation(vector<vector<int>> X, vector<int> Y);
	CMutualInformation(vector<int> X, vector<int> Y);
	double getMutualInformation();

	~CMutualInformation();
};




//Conditional mutual information
class CConditionalMutualInformation{
private:
	vector<vector<int>> X;
	vector<int> Y;
	vector<vector<int>> X_dondition;
	double conditionalMutualInformation;
	void calculateConditionalMutualInformation();

public:
	CConditionalMutualInformation(vector<int> X, vector<int> Y, vector<int> X_condition);
	CConditionalMutualInformation(vector<vector<int>> X, vector<int> Y, vector<int> X_condition);
	CConditionalMutualInformation(vector<vector<int>> X, vector<int> Y, vector<vector<int>> X_condition);
	double getConditionalMutualInformation();

	~CConditionalMutualInformation();
};