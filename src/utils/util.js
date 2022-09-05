export function debounce(func, wait) {
  let timeout;
  return function () {
    // 清空定时器
    if(timeout) clearTimeout(timeout);
    timeout = setTimeout(func, wait)
  }
}