export default function parseIndex (mdContent){


  const rowArr = mdContent.split('\r\n')
  const result = []
  for(const row of rowArr){
     
    const tp = row.split(' ')
    if(tp[0]=== '#'){
      result.push(`<h1>${tp[1]}</h1>`)
      continue
    }
    if(tp[0]=== '##'){
      result.push(`<h2>${tp[1]}</h2>`)
      continue
    }
    if(tp[0]=== '###'){
      result.push(`<h3>${tp[1]}</h3>`)
      continue
    }
    if(tp[0]=== '####'){
      result.push(`<h4>${tp[1]}</h4>`)
      continue
    }
    if(tp[0]=== '#####'){
      result.push(`<h5>${tp[1]}</h5>`)
      continue
    }
    if(tp[0]=== '######'){
      result.push(`<h6>${tp[1]}</h6>`)
      continue
    }
    if(tp[0]=== '#######'){
      result.push(`<h6>#${tp[1]}</h6>`)
      continue
    }
    
  }

  return result

}