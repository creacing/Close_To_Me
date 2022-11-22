var isValid = function (s) {
    const stack = []

    for (const e of s) {
        if (e === '(' || e === '[' || e === '{') {
            stack.push(e)
        }
        if (e === ')') {
            const t = stack[stack.length - 1] || stack[0]
            if (t === '(') {
                stack.pop()
                continue
            } else {
                stack.push(e)
            }
        }
        if (e === ']') {
            const t = stack[stack.length - 1] || stack[0]
            if (t === '[') {
                stack.pop()
                continue
            } else {
                stack.push(e)
            }
        }
        if (e === '}') {
            const t = stack[stack.length - 1] || stack[0]
            if (t === '{') {
                stack.pop()
                continue
            } else {
                stack.push(e)
            }
        }
    }

    return stack.length > 0 ? false : true
};

const s = ']'

console.log(isValid(s));