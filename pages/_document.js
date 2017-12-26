import Document, { Main, NextScript } from 'next/document';
import React from 'react';
import Store from '../components/Store.re';

export default class MyDocument extends Document {
  render() {
    return (
      <html>
        <body>
          <Store render={(dispatch, state) => <Main dispatch state />} />
          <NextScript />
        </body>
      </html>
    );
  }
}
