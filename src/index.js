import PthreadTest from './wasm/PthreadTest.mjs';

async function main() {
    const module = await new PthreadTest();
    module.test();
}

await main();
