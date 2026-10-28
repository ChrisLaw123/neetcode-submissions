class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        const stack = [];

        for (let c of s) {
            if (c === '(' || c ==='{' || c === '[') {
                stack.push(c);
            } else {
                if (c ==')' && stack[stack.length-1] == '(') {
                    stack.pop();
                } else if (c =='}' && stack[stack.length-1] == '{') {
                    stack.pop();
                } else if (c ==']' && stack[stack.length-1] == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return (stack.length == 0);
    }
}
