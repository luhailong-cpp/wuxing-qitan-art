const fs=require('node:fs'),path=require('node:path'),crypto=require('node:crypto');
const root=path.resolve(__dirname,'..');
const report=JSON.parse(fs.readFileSync(path.join(root,'docs/repository-export-20261015.json'),'utf8'));
let failed=0;
for(const entry of report.files){
 const file=path.resolve(root,entry.path);
 if(!file.startsWith(root+path.sep)||!fs.existsSync(file)){console.error('缺失或无效路径: '+entry.path);failed++;continue;}
 const data=fs.readFileSync(file);
 if(data.length!==entry.bytes||crypto.createHash('sha256').update(data).digest('hex')!==entry.sha256){console.error('哈希不符: '+entry.path);failed++;}
}
console.log(JSON.stringify({files:report.files.length,failed}));process.exitCode=failed?1:0;
