import About from '../components/About';
import Head from 'next/head';
import Link from 'next/link';
import Listings from '../components/Listings';
import Loading from '../components/Loading';
import PropTypes from 'prop-types';
import React, { Component } from 'react';
import { fetchListings } from '../utils/endpoints';

class Index extends Component {
  static async getInitialProps() {
    const resp = await fetchListings();
    const json = await resp.json();
    return { items: json.results };
  }

  render() {
    return (
      <div>
        <Head>
          <title>Evergreen Roots</title>
          <meta
            name="viewport"
            content="initial-scale=1.0, width=device-width"
          />
        </Head>
        <span>Home</span> |{' '}
        <Link href="/contact" prefetch>
          <a>Contact</a>
        </Link>
        <About />
        {this.props.items ? <Listings items={this.props.items} /> : <Loading />}
      </div>
    );
  }
}

Index.displayName = 'Index';

Index.propTypes = {
  items: PropTypes.array,
};

export default Index;
