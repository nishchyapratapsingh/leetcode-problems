class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
    	int n = arr.size();
    	stack<int> st;
    	long long arrMins = 0;
        for (int i = 0; i <= n; i++) {
            int currElem = i == n ? INT_MIN : arr[i];
        	while (!st.empty() && currElem < arr[st.top()]) {
        		int top = st.top();
        		st.pop();
        		int pse = st.empty() ? -1 : st.top();
        		int nse = i;
        		long long leftContr = top - pse;
        		long long rightContr = nse - top;
        		arrMins = (arrMins + (((leftContr * rightContr)) * arr[top] ) );
        	}

        	st.push(i);
        }

        stack<int> st2;

        long long arrMaxs = 0;
        for (int i = 0; i <= n; i++) {
            int currElem = i == n ? INT_MAX : arr[i];
        	while (!st2.empty() && currElem > arr[st2.top()]) {
        		int top = st2.top();
        		st2.pop();
        		int pge = st2.empty() ? -1 : st2.top();
        		int nge = i;
        		long long leftContr = top - pge;
        		long long rightContr = nge - top;
        		arrMaxs = (arrMaxs + (((leftContr * rightContr)) * arr[top] ) );
        	}

        	st2.push(i);
        }

        return arrMaxs - arrMins;
    }
};