

<template>
  <div class="inner">
    <div id="brand" class="affix">
      <div class="pjax">
        <RouterLink to="/" class="logo" rel="start" data-pjax-state>
          <p class="artboard">{{ author }}</p>
          <h1 itemprop="name headline" class="title">{{ title }}</h1>
        </RouterLink>
        <p class="meta" itemprop="description">{{ description }}</p>
      </div>
    </div>
  </div>
</template>
<script setup>
import { RouterLink } from "vue-router";
import config from "../../public/config";
const { author, title, description } = config;
</script>