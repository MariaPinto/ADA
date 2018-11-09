# include<iostream>
using namespace std;
void mochila_f(int n, float weight[], float val[], float capacity) {
   float x[n], tp = 0;
   int i, j, u;
   u = capacity;

	float div[n], temp;

   for (int i = 0; i < n; i++) {
      div[i] = val[i] / weight[i];
   }

   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (div[i] < div[j]) {
            temp = div[j];
            div[j] = div[i];
            div[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = val[j];
            val[j] = val[i];
            val[i] = temp;
         }
      }
   }
   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + val[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * val[i]);

	cout<<tp;

}

int main() {
   int num = 7, m = 15;
   float weight[num] = {2,3,5,7,1,4,1};
   float val[num] = {10,5,15,7,6,18,3};
   


   mochila_f(num, weight, val, m);
   return(0);
}
