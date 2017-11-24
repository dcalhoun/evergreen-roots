import Head from 'next/head';
import Link from 'next/link';
import React, { Component } from 'react';

class Contact extends Component {
  render() {
    return (
      <div>
        <Head>
          <title>Contact - Evergreen Roots</title>
          <meta
            name="viewport"
            content="initial-scale=1.0, width=device-width"
          />
        </Head>
        <Link href="/" prefetch>
          <a>Home</a>
        </Link>{' '}
        | <span>Contact</span>
        <div>Contact</div>
      </div>
    );
  }
}

Contact.displayName = 'Contact';

export default Contact;
