<template>
  <div class="segments posts">
    <article class="item show" v-for="article in articles">
      <div class="cover">
        <a :href="MOCKDATA.path" itemprop="url" :title="MOCKDATA.title" data-pjax-state>
          <img
            :data-src="MOCKDATA.imgSrc"
            :src="MOCKDATA.imgSrc"
            data-loaded="true"
            class="lozaded"
          />
        </a>
      </div>
      <div class="info">
        <div class="meta">
          <span class="item" :title="MOCKDATA.createTime">
            <span class="icon">
              <i class="ic i-calendar"></i>
            </span>
            <time
              itemprop="dateCreated datePublished"
              :datetime="MOCKDATA.dateTime"
            >{{MOCKDATA.date}}</time>
          </span>
          <span class="item" title="本文字数">
            <span class="icon">
              <i class="ic i-pen"></i>
            </span>
            <span>{{MOCKDATA.fontNums}}</span>
            <span class="text">字</span>
          </span>
          <span class="item" title="阅读时长">
            <span class="icon">
              <i class="ic i-clock"></i>
            </span>
            <span>{{MOCKDATA.readTime}}</span>
          </span>
        </div>
        <h3>
          <a
            :href="MOCKDATA.path"
            itemprop="url"
            :title="MOCKDATA.title"
            data-pjax-state
          >{{MOCKDATA.title}}</a>
        </h3>
        <div class="excerpt">{{MOCKDATA.description}}</div>
        <div class="meta footer">
          <span>
            <a :href="MOCKDATA.flagPath" itemprop="url" :title="MOCKDATA.flag" data-pjax-state>
              <i class="ic i-flag"></i>
              {{MOCKDATA.flag}}
            </a>
          </span>
        </div>
        <a
          :href="MOCKDATA.path"
          itemprop="url"
          :title="MOCKDATA.title"
          class="btn"
          data-pjax-state
        >more...</a>
      </div>
    </article>
  </div>
</template>

<script setup>
import MOCKDATA from '@/utils/MOCKDATA.js'
const articles = [MOCKDATA, MOCKDATA, MOCKDATA]
</script>
