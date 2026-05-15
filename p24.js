var list=[],baselist=[],altbaselist=[],listp=[];//listp;
var base=5,basenext=2;
const max=10000000;
var max_i2=2;
var counter=0;

let start=performance.now();

for(let i=0;i<max;i+=basenext){
  
  if(base*base<max){
    list.push(base*base);//search list
    baselist.push(base);//base list
    altbaselist.push(basenext);//base of searchlist
  }
  var count=0;
  for (var i2=0;i2<max_i2;i2++){//search list
    if(list[i2]==base){//every repeat value do this
      max_i2-1==i2 && max_i2++;
      count++;
      if(altbaselist[i2]==2){//base of searchlist is 2
        list[i2]=((baselist[i2]*2)+list[i2]);
        altbaselist[i2]=4;
      }else{
        list[i2]=((baselist[i2]*4)+list[i2]);
        altbaselist[i2]=2;
      }
    }
  }
  count==0&&listp.push(base);
  if((counter&1)===0){
    base+=2;
    basenext=4;
  }else{
    base+=4;
    basenext=2;
  }
  counter++;
}


console.dir(listp,{'maxArrayLength': null});
console.log("Ran  "+max);
console.log("p length "+listp.length);

console.log((performance.now()-start)/1000);

console.log("end");