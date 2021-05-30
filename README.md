# Current state
As checked-in, this repo can be built and run correctly (`yarn && yarn build && yarn start`, then open `localhost:8080` in your browser), however `yarn build` generates three JS files:
* `dist/main.js`
* `dist/src_wasm_PthreadTest_mjs.js`
* `dist/src_wasm_PthreadTest_worker_js.js`

When it does this, Webpack generates the following warnings:

```
WARNING in ./src/wasm/PthreadTest.worker.js 1:810-834
Critical dependency: the request of a dependency is an expression
 @ ./src/wasm/PthreadTest.mjs 9:413251-413311
 @ ./src/index.js 1:0-49 4:29-40

WARNING in [entry] [initial]
Circular dependency between chunks with runtime (main, src_wasm_PthreadTest_worker_js)
This prevents using hashes of each other and should be avoided.
```

The first warning seems ignoreable.  The second, however, is problematic and can cause webpack to hang until it dies from an out-of-memory error.

The hang can be triggered by uncommenting the `worker-loader` lines in `webpack.config.js` and then running `yarn build`.  Without having stepped through what `webpack` is doing behind the scenes, the most obvious culprit appears to be that circular dependency.  What's more, I'm pretty sure that this dependency will make it impossible to compile down to a single file with the worker inlined until that circular dependency is resolved.

## Suggestion
Maybe rather than having the `module` -> `worker` -> `module` circular dependency at compile time, instead pass the module to the worker at runtime just after the worker is instantiated.
