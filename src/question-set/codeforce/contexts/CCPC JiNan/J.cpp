// #include <bits/stdc++.h>
// using namespace std;
// int a[200003];
// int b[200003];
// int c[200003];
// int f[200003];
// map<int,int> mp1;
// map<int,int> mp2;
// map<int,int > mp3;
// struct cj
// {
//     int x,y,z;
// }chushi[200003];

// int main ()
// {
//    int t;
//    cin>>t;
//    while(t--)
//    {
//     int n;
//     cin>>n;
//     int i;
//     for(i =0;i < n;i++)
//     {
//         int s1,s2,s3;
//         cin>>s1>>s2>>s3;
//         chushi[i].x = s1;
//         chushi[i].y= s2;
//         chushi[i].z = s3;
//         mp1[s1]++;
//         mp2[s2]++;
//         mp3[s3]++;
//         if(a[s1] )
//     }
//     for(i =0;i < n;i++)
//     {
//         int aa,bb,cc;
//         aa=mp[chushi[i].x]-1;
//         bb=mp[chushi[i].y]-1;      
//         cc=mp[chushi[i].z]-1;
//         f[i]=max(aa,max(bb,cc));
//     }
//     sort(f,f+n);
//     int i;
//     int ans =0;
//     for(i=0;i<n;i++)
//     {
//         if(i == 0)
//             cout<<"0 ";
//         else
//         {
//             if(f[ans] < i)
//             {   
//                 mp1[f[ans].index]--;
//                 mp2[f[ans].index]--;
//                 mp3[f[ans].index]--;

//                 ans ++;
//             }
//             else
//                 continue;
//         }
//     }
//    }

// }
