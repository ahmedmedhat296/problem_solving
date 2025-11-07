#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        ll perimeter = 0;
        int nsides = 0;
        int odds=0;
        vector<ll> s(n);
        vector<ll> odd;
        map<ll, ll> cnt;
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
            cnt[s[i]]++;
        }
        for (auto [x, c] : cnt)
        {
            if (c % 2 == 0)
            {
                perimeter += c * x;
                nsides += c;
            }
            else
            {
                odd.push_back(x);
                perimeter += (c - 1) * x;
                nsides += (c - 1);
            }
        }
        if (perimeter)
        {
            if (odd.size() == 1 && perimeter>odd[0])
            {
                perimeter += odd[0];
                nsides++;
            }
            else
            {
                bool one=true;
                sort(odd.begin(), odd.end(), greater<ll>());
                int size=odd.size();
                for (int i = 0; i < size-1; i++)
                {
                    if (odd[i] - odd[i + 1] < perimeter)
                    {
                        perimeter += (odd[i] + odd[i + 1]);
                        nsides += 2;
                        one=false;
                        break;
                    }
                }
                if(one && odd.size()>1&&odd[size-1]<perimeter)
                {
                    perimeter+=odd[size-1];nsides++;
                }

            }
        }
            if (nsides < 3 || !perimeter)
                perimeter = 0;
        cout << perimeter << '\n';
    }
}
