//Ordena baseado no atributo
function bubbleSortByAttr(arr, attr, value_of_function){

    var len = arr.length;
    
    for (var i = len-1; i>=0; i--){

        for(var j = 1; j<=i; j++){

            if (value_of_function != undefined){
                if( arr[j-1][attr](value_of_function) > arr[j][attr](value_of_function) ){

                    var temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
            else {
                if( arr[j-1][attr] > arr[j][attr] ){

                    var temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }            
        }
    }
    return arr;        
}



//Cria variável CSS para unidade vh, sendo adaptável aos navegadores mobile
let vh = window.innerHeight * 0.01;
document.documentElement.style.setProperty('--vh', `${vh}px`);

window.addEventListener('resize', () => {

    let vh = window.innerHeight * 0.01;
    document.documentElement.style.setProperty('--vh', `${vh}px`);

});



//Desativa a rolagem do mouse sem desativar o scroll do JS

function noscroll() {
    window.scrollTo( 0, 0 );
}
/**Aplicação
 * DESATIVA: window.addEventListener('scroll', noscroll);
 * ATIVA: window.removeEventListener('scroll', noscroll);
 */