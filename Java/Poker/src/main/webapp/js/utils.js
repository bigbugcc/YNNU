
const Utils = {
    prefixZero(num, n) {
        return (Array(n).join(0) + num).slice(-n);
    }
}