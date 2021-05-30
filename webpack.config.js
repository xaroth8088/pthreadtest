import HtmlWebpackPlugin from 'html-webpack-plugin';

export default {
    mode: 'development',
    devtool: 'source-map',
    experiments: {
        topLevelAwait: true
    },
    plugins: [
        new HtmlWebpackPlugin()
    ],
    module: {
        rules: [
            // {
            //     test: /\.worker\.js$/,
            //     use: {
            //         loader: 'worker-loader',
            //         options: {
            //             inline: "no-fallback"
            //         }
            //     },
            // },
        ],
    }
};
