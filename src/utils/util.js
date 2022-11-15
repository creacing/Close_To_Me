export function debounce(wait, func) {
  let timeout;
  return function () {
    // 清空定时器
    if(timeout) clearTimeout(timeout);
    const args = arguments
    const that = this
    timeout = setTimeout(()=>{
      func.apply(that,args)
    }, wait)
  }
}