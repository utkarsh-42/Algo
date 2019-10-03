
function merge(left,right){
    let mergedArr = [] ;

    for(let i = 0 , j = 0 ; i < left.length || j < right.length;) {
        if(i < left.length && j < right.length) {
            if(left[i]<right[j]) {
                mergedArr.push(left[i]);
                i++;
            }
            else {
                mergedArr.push(right[j]);
                j++;
            }
        }

        else if(i>=left.length) {
            for(let l = j ; l < right.length;l++) {
                mergedArr.push(right[l]);
                j++;
            }
        }
        else if(j>=right.length){
            for(let l = i ; l < left.length;l++) {
                mergedArr.push(left[l]) ;
                 i++;
            }
        }

    }
    return mergedArr ;
}

function mergeSort(arr) {
    if(arr.length <= 1) {
        return arr;
    }
    let mid = Math.floor(arr.length/2);
    let left = arr.slice(0,mid);
    let right = arr.slice(mid);
    return merge(mergeSort(left),mergeSort(right)) ;

}


let arr = [8,5,6,0,12];


console.log(mergeSort(arr));