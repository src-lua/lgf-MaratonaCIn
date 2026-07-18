    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    bool compare (pair<int,string> i, pair<int,string> j) { return (i.first>j.first); }

    int32_t main()
    {
        int n;
        cin >> n;
        vector<int> v(n);
        //map<string,int> m;
        vector<pair<int, string>> arr(n);
        string c;
        for(int i =0;i<n;i++)
        {
            cin >> c;

            int x;
            cin >> x;
            arr[i] = {x*10,c};
            //m[c] = 10*x;
            int sum=0,menor=11,maior=-1;
            for(int j=0;j<6;j++)
            {
                cin >> x;
                sum+=x;
                if(x>maior) maior = x;
                if(x<menor) menor = x;
            }
            sum-=menor; sum-=maior;
            //m[c]+=sum;
            arr[i].first += sum;
        }
        

        int k = 0;
        int prev=-1;
        
        stable_sort(arr.begin(),arr.end(), compare);

        for(auto [b,a]:arr)
        {
            k++;
            if ((k>3 && b != prev) || k>1000) break; 
            cout << a << " "<< b<<"\n";
            prev = b;
        }
    }