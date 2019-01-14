
# Sobel and Laplacian Operator

## Theory

![derivative](https://github.com/qinhaihong-red/sobel_laplacian_operator/raw/master/images/derivative.png)

__The answer is to calculate difference to approximate gradient.__ Let's see it.


![difference](https://github.com/qinhaihong-red/sobel_laplacian_operator/raw/master/images/difference.png)

__In digit image processing, in order to obtain the difference talked above, we can do convolution or correlation calculation with specific spatial filter__: 

![sobel](https://github.com/qinhaihong-red/sobel_laplacian_operator/raw/master/images/sobel.png)

__As for Laplacian operaiton,we can obtain the result either by summing the calculated second order Sobel difference of the image in 2 directions talked above, or doing correlation calculation with the image using the kernels descpribed as below ：__


![laplacian](https://github.com/qinhaihong-red/sobel_laplacian_operator/raw/master/images/laplacian.png)

## Practise

In OpenCV, there are 2 functions :Sobel() and Laplacian(), which implement Sobel and Laplacian Operator.

But we can use the methods talked above to do the same thing without these built-in functions for better understanding. 

Here is a simple example：

![practise](https://github.com/qinhaihong-red/sobel_laplacian_operator/raw/master/images/practise.png)


__See the code for more details.__