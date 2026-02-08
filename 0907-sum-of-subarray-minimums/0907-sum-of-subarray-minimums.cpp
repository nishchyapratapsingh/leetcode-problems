class Solution {
	public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        stack<int> st;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
        	while (!st.empty() && arr[i] <= arr[st.top()]) {
        		int top = st.top();
        		st.pop();
        		int pse = st.empty() ? -1 : st.top();
        		int nse = i;
        		long long leftContr = top - pse;
        		long long rightContr = nse - top;
        		ans = (ans + (((leftContr * rightContr) % mod) * arr[top] ) % mod) % mod;
        	}

        	st.push(i);
        }

        while (!st.empty()) {
    		int top = st.top();
    		st.pop();
    		int pse = st.empty() ? -1 : st.top();
    		int nse = n;
    		long long leftContr = top - pse;
    		long long rightContr = nse - top;
			ans = (ans + (((leftContr * rightContr) % mod) * arr[top] ) % mod) % mod;
		}

        return (int)ans;
    }
};