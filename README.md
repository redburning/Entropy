# Entropy
## 1 Introduction
 The toolbox contains implementations of the most popular Shannon entropies, including the calculation of entropy, joint entropy, conditional entropy, mutual information, joint mutual information and conditional mutual information. The toolbox only supports discrete distributions, as for continuous data, we should do discretization beforhand. **One of the advantages of this package is that it is suitable for high-dimensional data, i.e. it can be used to calculate the joint entropy and joint mutual information of many variables**.
 
## 2 Examples
### 2.1 Calculation of entropy.
 Entropy of x: H(x)
 ``` C++
 vector<int> x = { 1, 1, 1, 0, 0 };
 vector<int> y = { 1, 0, 1, 1, 0 };
 CEntropy X(x);
 CEntropy Y(y);
 cout << X.getEntropy() << endl;
 cout << Y.getEntropy() << endl;
 
 console: 0.970951
          0.970951
 ```
### 2.2 Calculation of joint entropy.
 Joint entropy of x and y: H(x, y)
 ``` C++
 vector<vector<int>> xy;
 xy.push_back(x);
 xy.push_back(y);
 CEntropy XY(xy);
 cout << XY.getEntropy() << endl;
 
 console: 1.92193
 ```
### 2.3 Calculation of conditional entropy.
 Conditional entropy: H(x | y), x and y can be more than just a variable. 
 ``` C++
 CConditionalEntropy X_Y(x, y);
 cout << X_Y.getConditionalEntropy() << endl;
 
 console: 0.950978
 ```
### 2.4. Calculation of mutual information.
 Mutual information of x and y: I(x ; y)
 ``` C++
 CMutualInformation IXY(x, y);
 cout << IXY.getMutualInformation() << endl;
 
 console: 0.0199731
 ```
### 2.5. Calculation of joint mutual information.
 Joint mutual information of x, y and z: I(x, y ; z)
 ``` C++
 vector<int> z = { 1, 1, 0, 1, 0 };
 CMutualInformation IXYZ(xy, z);
 cout << IXYZ.getMutualInformation() << endl;
 
 console: 0.570951
 ```
### 2.6. Calculation of conditional mutual information.
 Conditional mutual information of x, y and z: I(x, y | z), x and z can be more than one variable. 
 ``` C++
 CConditionalMutualInformation IXY_Z(x, y, z);
 cout << IXY_Z.getConditionalMutualInformation() << endl;
 
 console: 0.550978
 ```
