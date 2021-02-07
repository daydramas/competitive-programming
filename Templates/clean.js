const fs = require('fs');
const path = require('path');

function clean() {
	const snippet = path.join(path.join(__dirname, '..'), '.vscode/cpp.code-snippets');
	let data = {};
	fs.writeFileSync(snippet, JSON.stringify(data, null, 4));
}

clean();