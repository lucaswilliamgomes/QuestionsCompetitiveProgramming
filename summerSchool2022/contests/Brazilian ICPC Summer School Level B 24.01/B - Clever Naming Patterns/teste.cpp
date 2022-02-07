//Verificação se existe o arquivo da planilha
if(!_pin.sheet) {
    _pin.sheetValidationMessage = "A planilha não existe";
    _pin.processError = true;
    return;
}
    
//VALIDAÇÃO DA PLANILHA
//Verifica se o arquivo possui extensão csv
if(_pin.sheet.contentType !== "text/csv" && _pin.sheet.contentType !== "application/vnd.ms-excel") {
    _pin.sheetValidationMessage = "O Arquivo deve ser do formato CSV";
    _pin.processError = true;
    return;
}

let content = _pin.sheet.getContentAsText("UTF-8");
let lines = -1;    //Descartando a linha do cabeçalho
//Conta a quantidade de linhas que a planilha possui
for(let i = 0; i < content.length; i++) {
    lines = content[i] === '\n' ? lines + 1 : lines;
}

//Se tem mais de 30 mil linhas o objeto não será processado
if(lines > 3) {
    _pin.sheetValidationMessage = "Planilha não importada por conter mais de 30.000 objetos. Encontrados " + lines + " linhas no arquivo.";
    _pin.processError = true;
    return;
}


//TRANSFORMAR PLANILHA EM JSON
//Quebra das linhas e celulas do arquivo csv
let text = content.split(/\r\n|,/);

//Variaveis auxiliares necessárias
let arrayOfObjects = [];
let obj= {};
let header = [
    "TIPO_DOCUMENTO",
    "FORMATO",
    "BM",
    "BM_ADICIONAL",
    "CPF",
    "NOME",
    "DATA_DOCUMENTO",
    "PERIODO",
    "SECRETARIA",
    "UNIDADE_LOTACAO",
    "VINCULO",
    "NUMERO_OFICIO",
    "CAMINHO_ARQUIVO",
    "CAMINHO_CONTEUDO_TEXTUAL",
    "DOCUMENTOS_RELACIONADOS"
    ];

//Remoção da linha do header
let fileHeader = text.splice(0,header.length);
let data = text.splice(0,header.length);

//Monta os nomes dos campos
for(var i=0 ; i < header.length ; i++) {
    obj[header[i]] = data[i];
}
arrayOfObjects.push(cloneObj(obj));

//Cria-se o array de documentos com os campos
while(data.length){
    data = text.splice(0,header.length);

    for(var i=0 ; i < header.length ; i++) {
        obj[header[i]] = data[i];
    }
    arrayOfObjects.push(cloneObj(obj));
}
//Apaga um ultimo objeto vazio criado pelo split que ocorre na ultima "," do csv
arrayOfObjects.pop();

_pin.indexSheet = arrayOfObjects.length;
_pin.jsonSheet = _utils.stringifyAsJson(arrayOfObjects);

// Variável que guarda quantos documentos serão enviados para o subprocesso de cada vez
const chunkSize = 5;    //Padrão: 1000
let tasksDocuments = chunkArray(arrayOfObjects, chunkSize);
_pin.objectsArrays = _utils.stringifyAsJson(tasksDocuments);


const jsonTeste = {
  "VINCULO":"MUNICIPALIZADOS",                                                                                                                                                                                                                         
  "UNIDADE_LOTACAO":"Unidade teste",
  "BM":"009999-9",
  "BM_ADICIONAL":"009999-9",
  "FORMATO":"NATO_DIGITAL",
  "SECRETARIA":"Secretaria teste",
  "CPF":"00000000000",
  "PERIODO":"2016",
  "TIPO_DOCUMENTO":"DOCUMENTO_SEFIP",
  "NUMERO_OFICIO":"9999/0000",
  "NOME":"Nome exemplo",
  "DATA_DOCUMENTO":"07/10/2021",
  "TITULO_DOCUMENTO" : "Titulo exemplo"
//   "CAMINHO_ARQUIVO":"f",
//   "CAMINHO_CONTEUDO_TEXTUAL":"f",
//   "DOCUMENTOS_RELACIONADOS":"g"
};

let documentData = {
    "additionalOfficerData" : {
        "enrollmentBulletin": jsonTeste.BM,
    },
    "documentDate" : jsonTeste.DATA_DOCUMENTO,
    "period": buildPeriod(jsonTeste.PERIODO),
    "CPF": jsonTeste.CPF,
    "departmentName": jsonTeste.SECRETARIA,
    "workingUnit": jsonTeste.UNIDADE_LOTACAO,
    "link": buildLink(jsonTeste.VINCULO),
    "letterNumber":jsonTeste.NUMERO_OFICIO
};

_utils.getMethod('_classId', ID_CLASS_OFFICIALDOCUMENT, 'createNewDocument')({
    "documentType": {"_id": buildDocumentType(jsonTeste.TIPO_DOCUMENTO)},
    "title": jsonTeste.TITULO_DOCUMENTO,
    "source": {"_id": "5dfa3c10ad0ab2006cefc75e"},
    "format": {"_id": buildFormat(jsonTeste.FORMATO)},
    "dataForDocumentCreation": documentData,
    //"file": <arquivo do documento>
});


function buildDocumentType(documentType){
    if (documentType === "PRONTUARIO_READAPTACAO_FUNCIONAL") {
        return "6086bcb2f5ad671e516c59aa";
    } else if (documentType === "PRONTUARIO_SEGURANCA_DO_TRABALHO") {
        return "6086bcc5f5ad671e516c59ef";
    } else if (documentType === "PRONTUARIO_ATENDIMENTOS") {
        return "6086bccef5ad671e516c5a1c";
    } else if (documentType === "PRONTUARIO_AVULSOS") {
        return "6086bcdcf5ad671e516c5a59";
    } else if (documentType === "PASTA_FUNCIONAL_ADMISSAO_REGISTRO") {
        return "6086bc16f5ad671e516c56b7";
    } else if (documentType === "PASTA_FUNCIONAL_BENEFICIOS") {
        return "6086bc23f5ad671e516c56ff";
    } else if (documentType === "PASTA_FUNCIONAL_PAGAMENTO") {
        return "6086bc67f5ad671e516c585c";
    } else if (documentType === "PASTA_FUNCIONAL_DIVERSOS") {
        return "6086bc6ef5ad671e516c5883";
    } else if (documentType === "PASTA_FUNCIONAL_BEPREM") {
        return "6086bc77f5ad671e516c58b6";
    } else if (documentType === "DOCUMENTO_SEFIP") {
        return "61e1b21bad26b65f6a423bf1";
    } else if (documentType === "DOCUMENTOS_FREQUENCIA") {
        return "61e1ba23ad26b65f6a8c9af0";
    } else if (documentType === "FREQUENCIA_CEDIDOS") {
        return "61e1b377ad26b65f6a538fa7";
    } else if (documentType === "OUTROS_FREQUENCIA_CEDIDOS") {
        // Criar esse tipo de documento
        return "";
    } else if (documentType === "OFICIOS_JUDICIAIS") {
        return "61e1b4b2ad26b65f6a59a802";
    } else {
        return "";
    }
}

function buildFormat(format){
    if (format === "NATO_DIGITAL") {
        return "5dc3400ff4fe0d665639aedc";
    } else if (format === "DIGITALIZADO") {
        return "5df90968ad0ab2006ceefb1d";
    } else {
        return "";
    }
}

function buildPeriod(period) {
    if (period === "1975") {
        return "Até 1975";
    } else if (period === "1976-1985") {
        return "De 1976 a 1985";
    } else if (period === "1986-1995") {
        return "De 1986 a 1995";
    } else if (period === "1996-2005") {
        return "De 1996 a 2005";
    } else if (period === "2006-2015") {
        return "De 2006 a 2015";
    } else if (period === "2016") {
        return "A partir de 2016";
    } else {
        return "";
    }
}

function buildLink(link) {
    if (link === "ESTATUTARIOS") {
        return "Estatutários";
    } else if (link === "CELETISTAS") {
        return "Celetistas";
    } else if (link === "ESTAGIARIOS") {
        return "Estagiários";
    } else if (link === "CONTRATOS_ADMINISTRATIVOS") {
        return "Contratos Administrativos";
    } else if (link === "MUNICIPALIZADOS") {
        return "Municipalizados";
    } else if (link === "OUTROS") {
        return "Outros";
    } else {
        return "";
    }
}

function cloneObj(obj){
    let newObject = Object.assign({},obj);
    return newObject;
}

// Função que transforma o array em array de arrays
function chunkArray(array, chunkSize) {
    let result = [];
    while(array.length) {
        result.push(array.splice(0, chunkSize));
    }
    return result;
}
