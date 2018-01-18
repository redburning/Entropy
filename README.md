# Entropy
## Introduction
 The toolbox contains implementations of the most popular Shannon entropies, including the calculation of entropy, joint entropy, conditional entropy, mutual information, joint mutual information and conditional mutual information. The toolbox only supports discrete distributions, as for continuous data, we should do discretization beforhand. **One of the advantages of this package is that it is suitable for high-dimensional data, i.e. it can be used to calculate the joint entropy and joint mutual information of many variables**.
 
## Examples
 1. Calculation of entropy.
 ``` C++
 vector<int> x = { 1, 1, 1, 0, 0 };
 CEntropy X(x);
 cout << X.getEntropy() << endl;
 console: 0.970951
 ```
 2. Calculation of joint entropy.
 3. Calculation of conditional entropy.
 4. Calculation of mutual information.
 5. Calculation of joint mutual information.
 6. Calculation of conditional mutual information.
